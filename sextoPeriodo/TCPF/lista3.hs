import Data.Char
import Control.Applicative

newtype Parser a = P {rodaParser :: String -> Maybe (a, String)}

fun :: Char -> Int
fun 'H' = 10
fun _ = 9

satisfaz :: (Char -> Bool) -> Parser Char
satisfaz condição = P f
    where
        f (x:xs) = if condição x then Just (x, xs) else Nothing
        f [] = Nothing

instance Functor Parser where
    fmap :: (a -> b) -> Parser a -> Parser b
    fmap fun (P rodaParser) = P $ \s ->
        case rodaParser s of
            Just (x, xs) -> Just (fun x, xs)
            Nothing -> Nothing

instance Applicative Parser where
    pure a = P (\s -> Just (a, s))
    p <*> q = P (\s -> case rodaParser p s of
                        Nothing -> Nothing
                        Just (f, s') -> rodaParser (fmap f q) s')

instance Alternative Parser where
    empty = P (const Nothing)
    P p1 <|> P p2 = P $ \s -> p1 s <|> p2 s

caracter :: Char -> Parser Char
caracter c = satisfaz (== c)

zeroOuMais :: Parser a -> Parser [a]
zeroOuMais p = umOuMais p <|> pure []

umOuMais :: Parser a -> Parser [a]
umOuMais p = (:) <$> p <*> zeroOuMais p

type Identif = String

letra :: Parser Char
letra = satisfaz isAlpha

alfanum :: Parser Char
alfanum = satisfaz isAlphaNum

parseIdentif :: Parser Identif
parseIdentif = (:) <$> letra <*> zeroOuMais alfanum

data Átomo = N Integer | I Identif
    deriving (Eq, Show)

parserInteger :: Parser Integer
parserInteger = read <$> umOuMais (satisfaz isDigit)

parseÁtomo :: Parser Átomo
parseÁtomo = (N <$> parserInteger) <|> (I <$> parseIdentif)

parseEspaços :: Parser String
parseEspaços = zeroOuMais (satisfaz isSpace)

data SExpr = A Átomo | C [SExpr]
    deriving (Eq, Show)

parseListaSExpr :: Parser [SExpr]
parseListaSExpr = caracter '(' *> zeroOuMais parseSExpr <* caracter ')'

parseSExpr :: Parser SExpr
parseSExpr = parseEspaços *> ((A <$> parseÁtomo)  <|> (C <$> parseListaSExpr)) <* parseEspaços  
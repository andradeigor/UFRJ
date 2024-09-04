



newtype Parser a = P {rodaParser :: String -> Maybe (a, String)}

satisfaz :: (Char -> Bool) -> Parser Char
satisfaz condição = P f
  where
    f (x:xs) = if condição x then Just (x, xs) else Nothing
    f [] = Nothing


Instance Functor Parser where
     fmap :: (a -> b) -> Parser a -> Parser b
     
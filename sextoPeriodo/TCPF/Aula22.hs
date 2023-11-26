module Aula22 where

data Foo = Hugo | Matheus
  deriving (Eq, Show)

f :: String -> Foo
f "oi"    = _
f "tchau" = undefined
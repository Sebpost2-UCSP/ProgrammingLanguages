module Main where

iteration :: Int -> Int -> Int -> Int
iteration x y z = if x==y then z else iteration x (y+1) (z+1) 

minus :: Int -> Int -> Int
minus x y = if x==y then 0 else iteration x y 0

mymod :: Int -> Int -> Int
mymod x y = if ((minus x y)<(y)) then ((minus y (minus x y))) else mymod (minus x y) y

gcdX :: Int -> Int -> Int
gcdX x y = [v|v<-[2..1000], x `mod` v == 0 && y `mod` v == 0]!!(length([v|v<-[2..1000], x `mod` v == 0 && y `mod` v == 0])-1)

main = do
  print(minus 8 4)
  print(gcdX 36 60)
  print(mymod 16 3)
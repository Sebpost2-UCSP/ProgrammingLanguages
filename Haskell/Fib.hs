module Main where

fib :: Integer -> Integer
fib 0=0
fib 1=1
fib n=fib(n-1) + fib(n-2)

delete_:: Interger->[Interger]->[Interger]
delete_:: []=[]
delete_(a,b)=let x[]=takeWhile (/= b)a

main = do 
   --Ejercicio 1 FIBONACCI 
    print(fib(7))  
   

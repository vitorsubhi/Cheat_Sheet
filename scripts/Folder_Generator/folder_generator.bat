@echo off
set /p first=Primeira pasta: 
set /p last=Ultima pasta: 
for /l %%x in (%first%, 1, %last%) do (
   mkdir [%%x]
)
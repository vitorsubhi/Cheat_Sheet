; ModuleID = 'test.txt'
source_filename = "test.txt"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i16 @main() local_unnamed_addr {
entry:
  tail call void @init()
  %prntaux = alloca i16, align 2
  store i16 3, ptr %prntaux, align 2
  call void @print(i8 0, ptr nonnull %prntaux)
  ret i16 0
}

declare void @init() local_unnamed_addr

declare void @print(i8, ptr) local_unnamed_addr

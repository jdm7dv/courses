(* Example 8.14 *)
(* This is Modula-3 *)

MODULE Main;
IMPORT IO;

VAR
    mat1 : ARRAY [1..10], [1..10] OF REAL;
    mat2 : ARRAY [1..10] OF ARRAY [1..10] OF REAL;

BEGIN
    mat1[3, 4] := 10.0;
    mat1[4][3] := 11.0;
    mat2[3, 4] := 10.0;
    mat2[4][3] := 11.0;
    IO.PutReal(mat1[3][4]);
    IO.PutReal(mat1[4, 3]);
    IO.PutReal(mat2[3][4]);
    IO.PutReal(mat2[4, 3]);
END Main.

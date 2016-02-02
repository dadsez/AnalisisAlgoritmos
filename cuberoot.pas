program cuberoot;

{* ------------------------------------------------------------------------- *}
function CubeRoot( var a : real ; var error : real ) : real;
var
   xPrev : real;
   xNext : real;
   diff  : real;
begin
   xPrev := a;
   repeat
      xNext := ( ( 2.0 * xPrev ) + ( a / ( xPrev * xPrev ) ) ) / 3.0;
      diff := abs( xPrev - xNext );
      xPrev := xNext;
   until ( diff < error );
   CubeRoot := xNext;
end;

{* ------------------------------------------------------------------------- *}
var
   N     : integer;
   a     : real;
   error : real;
begin
   Read( N );
   Read( error );
   for n := 0 to N - 1 do
   begin
      Read( a );
      a := CubeRoot( a, error );
      Writeln( a:0:8 );
   end;
end.

{ eof - cuberoot.pas}

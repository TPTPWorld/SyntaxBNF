%------------------------------------------------------------------------------
% File     : PUZ143^1 : TPTP v9.0.0. Released v6.2.0.
% Domain   : Puzzles
% Problem  : Labyrinth3
% Version  : Especial.
% English  : An impossible maze.

% Refs     : [Cam14] Camarero (2014), Email to Geoff Sutcliffe
% Source   : [Cam14]
% Names    : labyrinth3 [Cam14]

% Status   : CounterSatisfiable
% Rating   : 0.67 v9.0.0, 0.75 v8.1.0, 0.60 v7.4.0, 0.75 v7.2.0, 0.67 v6.4.0, 1.00 v6.2.0
% Syntax   : Number of formulae    :   76 (  37 unt;  37 typ;  20 def)
%            Number of atoms       :   67 (  41 equ;   0 cnn)
%            Maximal formula atoms :    3 (   1 avg)
%            Number of connectives :   92 (   2   ~;   0   |;   0   &;  86   @)
%                                         (   0 <=>;   4  =>;   0  <=;   0 <~>)
%            Maximal formula depth :   10 (   2 avg)
%            Number of types       :    4 (   3 usr)
%            Number of type conns  :    6 (   6   >;   0   *;   0   +;   0  <<)
%            Number of symbols     :   37 (  34 usr;  32 con; 0-2 aty)
%            Number of variables   :   12 (   0   ^;  12   !;   0   ?;  12   :)
% SPC      : TH0_CSA_EQU_NAR

% Comments :
%------------------------------------------------------------------------------
thf(position_type,type,
    position: $tType ).

thf(direction_type,type,
    direction: $tType ).

thf(left_type,type,
    left: direction ).

thf(right_type,type,
    right: direction ).

thf(top_type,type,
    top: direction ).

thf(bottom_type,type,
    bottom: direction ).

thf(next_type,type,
    next: position > direction > position ).

thf(next_comm,axiom,
    ! [D1: direction,D2: direction,P: position] :
      ( ( next @ ( next @ P @ D1 ) @ D2 )
      = ( next @ ( next @ P @ D2 ) @ D1 ) ) ).

thf(left_right,axiom,
    ! [P: position] :
      ( ( next @ ( next @ P @ left ) @ right )
      = P ) ).

thf(top_bottom,axiom,
    ! [P: position] :
      ( ( next @ ( next @ P @ top ) @ bottom )
      = P ) ).

thf(wall_type,type,
    wall: position > $o ).

%----Inductive MoveList. For the moment we do not include the inductive axioms.
thf(movelist_type,type,
    movelist: $tType ).

thf(nomove_type,type,
    nomove: movelist ).

thf(movedir_type,type,
    movedir: movelist > direction > movelist ).

%----The position of the player after a list of movements
thf(playerpos_type,type,
    playerpos: movelist > position ).

thf(player_move_legal,axiom,
    ! [PO: position,M: movelist,D: direction] :
      ( ( ( playerpos @ M )
        = PO )
     => ( ~ ( wall @ ( next @ PO @ D ) )
       => ( ( playerpos @ ( movedir @ M @ D ) )
          = ( next @ PO @ D ) ) ) ) ).

thf(player_move_illegal,axiom,
    ! [PO: position,M: movelist,D: direction] :
      ( ( ( playerpos @ M )
        = PO )
     => ( ( wall @ ( next @ PO @ D ) )
       => ( ( playerpos @ ( movedir @ M @ D ) )
          = PO ) ) ) ).

thf(c00_type,type,
    c00: position ).

thf(c10_type,type,
    c10: position ).

thf(c20_type,type,
    c20: position ).

thf(c30_type,type,
    c30: position ).

thf(c40_type,type,
    c40: position ).

thf(c01_type,type,
    c01: position ).

thf(c11_type,type,
    c11: position ).

thf(c21_type,type,
    c21: position ).

thf(c31_type,type,
    c31: position ).

thf(c41_type,type,
    c41: position ).

thf(c02_type,type,
    c02: position ).

thf(c12_type,type,
    c12: position ).

thf(c22_type,type,
    c22: position ).

thf(c32_type,type,
    c32: position ).

thf(c42_type,type,
    c42: position ).

thf(c03_type,type,
    c03: position ).

thf(c13_type,type,
    c13: position ).

thf(c23_type,type,
    c23: position ).

thf(c33_type,type,
    c33: position ).

thf(c43_type,type,
    c43: position ).

thf(c04_type,type,
    c04: position ).

thf(c14_type,type,
    c14: position ).

thf(c24_type,type,
    c24: position ).

thf(c34_type,type,
    c34: position ).

thf(c44_type,type,
    c44: position ).

thf(c10_defin,definition,
    ( c10
    = ( next @ c00 @ right ) ) ).

thf(c20_defin,definition,
    ( c20
    = ( next @ c10 @ right ) ) ).

thf(c30_defin,definition,
    ( c30
    = ( next @ c20 @ right ) ) ).

thf(c40_defin,definition,
    ( c40
    = ( next @ c30 @ right ) ) ).

thf(c01_defin,definition,
    ( c01
    = ( next @ c00 @ top ) ) ).

thf(c02_defin,definition,
    ( c02
    = ( next @ c01 @ top ) ) ).

thf(c03_defin,definition,
    ( c03
    = ( next @ c02 @ top ) ) ).

thf(c04_defin,definition,
    ( c04
    = ( next @ c03 @ top ) ) ).

thf(c11_defin,definition,
    ( c11
    = ( next @ c10 @ top ) ) ).

thf(c12_defin,definition,
    ( c12
    = ( next @ c11 @ top ) ) ).

thf(c13_defin,definition,
    ( c13
    = ( next @ c12 @ top ) ) ).

thf(c14_defin,definition,
    ( c14
    = ( next @ c13 @ top ) ) ).

thf(c21_defin,definition,
    ( c21
    = ( next @ c20 @ top ) ) ).

thf(c22_defin,definition,
    ( c22
    = ( next @ c21 @ top ) ) ).

thf(c23_defin,definition,
    ( c23
    = ( next @ c22 @ top ) ) ).

thf(c24_defin,definition,
    ( c24
    = ( next @ c23 @ top ) ) ).

thf(c31_defin,definition,
    ( c31
    = ( next @ c30 @ top ) ) ).

thf(c32_defin,definition,
    ( c32
    = ( next @ c31 @ top ) ) ).

thf(c33_defin,definition,
    ( c33
    = ( next @ c32 @ top ) ) ).

thf(c34_defin,definition,
    ( c34
    = ( next @ c33 @ top ) ) ).

%----Exercise 3. You cannot go from * to +
thf(c00_axiom,axiom,
    ( ( wall @ c00 )
    = $true ) ).

thf(c10_axiom,axiom,
    ( ( wall @ c10 )
    = $true ) ).

thf(c20_axiom,axiom,
    ( ( wall @ c20 )
    = $true ) ).

thf(c30_axiom,axiom,
    ( ( wall @ c30 )
    = $false ) ).

thf(c01_axiom,axiom,
    ( ( wall @ c01 )
    = $true ) ).

thf(c11_axiom,axiom,
    ( ( wall @ c11 )
    = $false ) ).

thf(c21_axiom,axiom,
    ( ( wall @ c21 )
    = $true ) ).

thf(c31_axiom,axiom,
    ( ( wall @ c31 )
    = $false ) ).

thf(c02_axiom,axiom,
    ( ( wall @ c02 )
    = $true ) ).

thf(c12_axiom,axiom,
    ( ( wall @ c12 )
    = $true ) ).

thf(c22_axiom,axiom,
    ( ( wall @ c22 )
    = $true ) ).

thf(c32_axiom,axiom,
    ( ( wall @ c32 )
    = $false ) ).

thf(start_axiom,axiom,
    ( ( playerpos @ nomove )
    = c11 ) ).

thf(exercise,conjecture,
    ! [M: movelist] :
      ( ( playerpos @ M )
     != c31 ) ).

%------------------------------------------------------------------------------

%------------------------------------------------------------------------------
% File     : PUZ081_8 : TPTP v9.0.0. Released v8.0.0.
% Domain   : Puzzles
% Problem  : 1 of http://philosophy.hku.hk/think/logic/knight.php
% Version  : Especial.
% English  : A very special island is inhabited only by knights and knaves.
%            Knights always tell the truth, and knaves always lie. You meet two
%            inhabitants: Zoey and Mel. Zoey tells you that Mel is a knave. Mel
%            says, `Neither Zoey nor I are knaves'. Who is a knight and who is
%            a knave?

% Refs     :
% Source   : [TPTP]
% Names    :

% Status   : Theorem
% Rating   : 0.00 v8.1.0
% Syntax   : Number of formulae    :   11 (   2 unt;   5 typ;   0 def)
%            Number of atoms       :   13 (   0 equ)
%            Maximal formula atoms :    2 (   1 avg)
%            Number of connectives :   10 (   3   ~;   0   |;   4   &)
%                                         (   0 <=>;   2  =>;   0  <=;   1 <~>)
%            Maximal formula depth :    5 (   3 avg)
%            Maximal term depth    :    1 (   1 avg)
%            Number of FOOLs       :    6 (   2 fml;   4 var)
%            Number of types       :    2 (   0 usr)
%            Number of type conns  :    4 (   3   >;   1   *;   0   +;   0  <<)
%            Number of predicates  :    3 (   3 usr;   0 prp; 1-2 aty)
%            Number of functors    :    2 (   2 usr;   2 con; 0-0 aty)
%            Number of variables   :    7 (   5   !;   2   ?;   7   :)
% SPC      : TX0_THM_NEQ_NAR

% Comments : Translated to TXF from the THF version.
%------------------------------------------------------------------------------
%----Type declarations
tff(mel_type,type,
    mel: $i ).

tff(zoey_type,type,
    zoey: $i ).

tff(knight_type,type,
    knight: $i > $o ).

tff(knave_type,type,
    knave: $i > $o ).

tff(says_type,type,
    says: ( $i * $o ) > $o ).

%----A very special island is inhabited only by knights and knaves.
tff(knights_xor_knaves,axiom,
    ! [P: $i] :
      ( knight(P)
    <~> knave(P) ) ).

%----Knights always tell the truth
tff(knights_tell_truth,axiom,
    ! [P: $i,S: $o] :
      ( ( knight(P)
        & says(P,(S)) )
     => (S) ) ).

%----Knaves always lie
tff(knaves_lie,axiom,
    ! [P: $i,S: $o] :
      ( ( knave(P)
        & says(P,(S)) )
     => ~ (S) ) ).

%----Zoey says 'Mel is a knave'
tff(zoey_speaks,axiom,
    says(zoey,knave(mel)) ).

%----Mel says `Neither Zoey nor I are knaves.'
tff(mel_speaks,axiom,
    says(mel,
      ( ~ knave(zoey)
      & ~ knave(mel) )) ).

%----What are Zoey and Mel
tff(who_is_knight_and_knave,conjecture,
    ? [Knight: $i,Knave: $i] :
      ( knight(Knight)
      & knave(Knave) ) ).

%------------------------------------------------------------------------------

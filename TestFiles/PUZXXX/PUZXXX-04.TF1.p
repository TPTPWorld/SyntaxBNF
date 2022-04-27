%----TF1
tff(dog_decl,type,      dog: $tType ).
tff(human_decl,type,    human: $tType ).
tff(biter_decl,type,    biter: $tType > $tType ).
tff(odie_decl,type,     odie: biter(dog) ).
tff(jon_decl,type,      jon: human ).
tff(owner_of_decl,type, owner_of: !>[BiterType: $tType]: (biter(BiterType) > human ) ).
tff(bit_decl,type,      bit: !>[BiterType: $tType]: ( (biter(BiterType) * human * $int) > $o ) ).
tff(hates_decl,type,    hates: (human * human) > $o ).

tff(jon_owns_odie,axiom,
    jon = owner_of(dog,odie) ).

tff(odie_bit_jon_twice,axiom,
    bit(dog,odie,jon,2) ).

tff(another_dog_bit_jon_twice,axiom,
    ? [D: biter(dog)] :
      ( D != odie
      & jon != owner_of(dog,D)
      & bit(dog,D,jon,2) ) ).

tff(hate_the_multi_biter_any,axiom,
    ! [T: $tType,B: biter(T),H: human,N: $int] :
      ( ( H != owner_of(T,B)
        & bit(T,B,H,N) 
        & $greater(N,1) )
     => hates(H,owner_of(T,B)) ) ).

tff(jon_hates_another_human,conjecture,
    ? [H: human] :
      ( H != jon
      & hates(jon,H) ) ).


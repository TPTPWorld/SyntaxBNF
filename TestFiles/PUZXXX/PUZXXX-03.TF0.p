%----TF0
tff(dog_decl,type,      dog: $tType ).
tff(human_decl,type,    human: $tType ).
tff(odie_decl,type,     odie: dog ).
tff(jon_decl,type,      jon: human ).
tff(owner_of_decl,type, owner_of: dog > human ).
tff(bit_decl,type,      bit: (dog * human * $int) > $o ).
tff(hates_decl,type,    hates: (human * human) > $o ).

tff(jon_owns_odie,axiom,
    jon = owner_of(odie) ).

tff(odie_bit_jon_twice,axiom,
    bit(odie,jon,2) ).

tff(another_dog_bit_jon_twice,axiom,
    ? [D: dog] :
      ( D != odie
      & jon != owner_of(D)
      & bit(D,jon,2) ) ).

tff(hate_the_multi_biter_dog,axiom,
    ! [D: dog,H: human,N: $int] :
      ( ( H != owner_of(D)
        & bit(D,H,N) 
        & $greater(N,1) )
     => hates(H,owner_of(D)) ) ).

tff(jon_hates_another_human,conjecture,
    ? [H: human] :
      ( H != jon
      & hates(jon,H) ) ).


%----TX1
tff(dog_decl,type,      dog: $tType ).
tff(human_decl,type,    human: $tType ).
tff(biter_decl,type,    biter: $tType > $tType ).
tff(odie_decl,type,     odie: biter(dog) ).
tff(jon_decl,type,      jon: human ).
tff(owner_of_decl,type, owner_of: !>[BiterType: $tType]: (biter(BiterType) > human ) ).
tff(bit_decl,type,      bit: !>[BiterType: $tType]: ( (biter(BiterType) * human * $int) > $o ) ).
tff(hates_decl,type,    hates: (human * human) > $o ).
tff(feeds_decl,type,    feeds: (human * biter(dog)) > $o ).
tff(chases_decl,type,   chases: (human * biter(dog)) > $o ).
tff(says_decl,type,     says: (human * $o) > $o ).

tff(jon_owns_odie,axiom,
    jon = owner_of(dog,odie) ).

tff(odie_bit_jon_twice,axiom,
    bit(dog,odie,jon,2) ).

tff(hate_the_multi_biter_any,axiom,
    ! [T: $tType,B: biter(T),H: human,N: $int] :
      ( ( H != owner_of(T,B)
        & bit(T,B,H,N) 
        & $greater(N,1) )
     => hates(H,owner_of(T,B)) ) ).

tff(feed_the_non_biter_dog,axiom,
    ! [D: biter(dog),H: human] :
      $ite(
        ? [N: $int] :
          ( bit(dog,D,H,N)
          & $greater(N,0) ),
        chases(H,D),
        feeds(H,D)) ).

tff(jon_says_a_dog_bit_him_twice,axiom,
    ? [D: biter(dog)] :
      ( D != odie
      & jon != owner_of(dog,D)
      & says(jon,bit(dog,D,jon,2)) ) ).

tff(jon_says_truth,axiom,
    ! [S: $o] :
      ( says(jon,S)
     => S ) ).

tff(jon_chases_and_hates,conjecture,
    ? [D: biter(dog),H: human] :
      ( chases(jon,D)
      & H != jon
      & hates(jon,H) ) ).


%----NX0
tff(garfield,logic,
        $modal == [
          $constants == $rigid,
          $quantification == $constant,
          $modalities == $modal_system_S5 ] ).

tff(dog_decl,type,      dog: $tType ).
tff(human_decl,type,    human: $tType ).
tff(odie_decl,type,     odie: dog ).
tff(jon_decl,type,      jon: human ).
tff(owner_of_decl,type, owner_of: dog > human ).
tff(bit_decl,type,      bit: (dog * human * $int) > $o ).
tff(hates_decl,type,    hates: (human * human) > $o ).
tff(feeds_decl,type,    feeds: (human * dog) > $o ).
tff(chases_decl,type,   chases: (human * dog) > $o ).
tff(says_decl,type,     says: (human * $o) > $o ).

tff(jon_owns_odie,axiom,
    jon = owner_of(odie) ).

tff(odie_bit_jon_twice,axiom,
    bit(odie,jon,2) ).

tff(hate_the_multi_biter_dog,axiom,
    ! [D: dog,H: human,N: $int] :
      ( ( H != owner_of(D)
        & bit(D,H,N) 
        & $greater(N,1) )
     => {$necessary(#arlene)}(hates(H,owner_of(D))) ) ).

tff(feed_the_non_biter_dog,axiom,
    ! [D: dog,H: human] :
      $ite(
        ? [N: $int] :
          ( bit(D,H,N)
          & $greater(N,0) ),
        chases(H,D),
        feeds(H,D)) ).

tff(jon_says_a_dog_bit_him_twice,axiom,
    ? [D: dog] :
      ( D != odie
      & jon != owner_of(D)
      & says(jon,bit(D,jon,2)) ) ).

tff(jon_says_truth,axiom,
    ! [S: $o] :
      ( says(jon,S)
     => S ) ).

tff(jon_chases_and_hates,conjecture,
    ? [D: dog,H: human] :
      ( {$possible(#garfield)}(chases(jon,D))
      & H != jon
      & hates(jon,H) ) ).


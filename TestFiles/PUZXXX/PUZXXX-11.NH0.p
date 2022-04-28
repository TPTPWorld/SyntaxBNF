%----NH0
thf(semantics,logic,(
  $modal ==
    [ $constants == $rigid,
      $quantification == $constant,
      $modalities == $modal_system_S5 ] )).

thf(dog_decl,type,       dog: $tType ).
thf(human_decl,type,     human: $tType ).
thf(odie_decl,type,      odie: dog ).
thf(jon_decl,type,       jon: human ).
thf(owner_of_decl,type,  owner_of: dog > human ).
thf(owns_decl,type,      owns: human > dog > $o ).
thf(bit_decl,type,       bit: dog > human > $int > $o ).
thf(hates_decl,type,     hates: human > human > $o ).
thf(feeds_decl,type,     feeds: human > dog > $o ).
thf(chases_decl,type,    chases: human > dog > $o ).
thf(says_decl,type,      says: human > $o > $o ).

thf(owns_defn,definition,
    ( owns = ( ^ [H: human,D: dog] : ( H = ( owner_of @ D ) ) ) ) ).

thf(jon_owns_odie,axiom, owns @ jon @ odie ).

thf(odie_bit_jon_twice,axiom, bit @ odie @ jon @ 2 ).

thf(hate_the_multi_biter_dog,axiom,
    ! [D: dog,H: human,N: $int] :
      ( ( ~ ( owns @ H @ D )
        & ( bit @ D @ H @ N )
        & ( $greater @ N @ 1 ) )
     => ( {$necessary(#arlene)} @ ( hates @ H @ ( owner_of @ D ) ) ) ) ).

thf(feed_the_non_biter_dog,axiom,
    ! [D: dog,H: human] :
      $ite(
        ? [N: $int] : 
          ( ( bit @ D @ H @ N )
          & ( $greater @ N @ 0 ) ),
        chases @ H @ D,
        feeds @ H @ D) ).

thf(jon_says_a_dog_bit_him_twice,axiom,
    ? [D: dog] :
      ( ( D != odie )
      & (~ ( owns @ jon @ D ))
      & ( says @ jon @ ( bit @ D @ jon @ 2 ) ) ) ).

thf(jon_says_truth,axiom,
    ! [S: $o] :
      ( ( says @ jon @ S )
     => S ) ).

thf(jon_chases_and_feels,conjecture,
    ? [D:dog,H: human,F: human > human > $o] :
      ( ( {$possible(#garfield)} @ ( chases @ jon @ D ) )
      & ( H != jon )
      & ( F @ jon @ H ) ) ).


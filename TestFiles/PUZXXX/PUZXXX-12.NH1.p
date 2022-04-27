%----NH1
tff(semantics,logic,(
  $modal ==
    [ $constants == $rigid,
      $quantification == $constant,
      $modalities == $modal_system_S5 ] )).

thf(dog_decl,type,      dog: $tType ).
thf(human_decl,type,    human: $tType ).
thf(biter_decl,type,    biter: $tType > $tType ).
thf(odie_decl,type,     odie: (biter @ dog) ).
thf(jon_decl,type,      jon: human ).
thf(owner_of_decl,type, owner_of: !>[BiterType: $tType] : ( ( biter @ BiterType ) > human ) ).
thf(owns_decl,type,     owns: !>[BiterType: $tType] : ( human > ( biter @ BiterType ) > $o ) ).
thf(bit_decl,type,      bit: !>[BiterType: $tType] : ( ( biter @ BiterType ) > human > $int > $o ) ).
thf(hates_decl,type,    hates: human > human > $o ).
thf(feeds_decl,type,    feeds: human > (biter @ dog) > $o ).
thf(chases_decl,type,   chases: human > (biter @ dog) > $o ).
thf(says_decl,type,     says: human > $o > $o ).

thf(owns_defn,definition,
    ( owns
    = ( ^ [T: $tType,H: human,B: biter @ T] : ( H = ( owner_of @ T @ B ) ) ) ) ).

thf(jon_owns_odie,axiom,
    owns @ dog @ jon @ odie ).

thf(odie_bit_jon_twice,axiom,
    bit @ dog @ odie @ jon @ 2 ).

thf(hate_the_multi_biter_any,axiom,
    ! [T: $tType,B: biter @ T,H: human,N: $int] :
      ( ( ~ ( owns @ T @ H @ B )
        & ( bit @ T @ B @ H @ N )
        & ( $greater @ N @ 1 ) )
     => ( {$necessary(#garfield)} @ ( hates @ H @ ( owner_of @ T @ B ) ) ) ) ).

thf(feed_the_non_biter_dog,axiom,
    ! [D: biter @ dog,H: human] :
      $ite(
        ? [N: $int] :
          ( ( bit @ dog @ D @ H @ N )
          & ( $greater @ N @ 0 ) ),
        chases @ H @ D,
        feeds @ H @ D) ).

thf(jon_says_a_dog_bit_him_twice,axiom,
    ? [D: biter @ dog] :
      ( ( D != odie )
      & ~ ( owns @ dog @ jon @ D )
      & ( says @ jon @ ( bit @ dog @ D @ jon @ 2 ) ) ) ).

thf(jon_says_truth,axiom,
    ! [S: $o] :
      ( ( says @ jon @ S )
     => S ) ).

thf(jon_chases_and_feels,conjecture,
    ? [D: biter @ dog,H: human,F: human > human > $o] :
      ( ( {$possible(#garfield)} @ ( chases @ jon @ D ) )
      & ( H != jon )
      & ( F @ jon @ H ) ) ).


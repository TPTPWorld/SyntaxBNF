%----FOF
fof(odie_is_a_dog,axiom,
    dog(odie) ).

fof(jon_owns_odie,axiom,
    jon = owner_of(odie) ).

fof(all_owners_are_human,axiom,
    ! [D] :
      ( dog(D)
     => human(owner_of(D)) ) ).

fof(odie_bit_jon,axiom,
    bit(odie,jon) ).

fof(another_dog_bit_jon,axiom,
    ? [D] :
      ( dog(D)
      & D != odie
      & jon != owner_of(D)
      & bit(D,jon) ) ).

fof(hate_the_biter,axiom,
    ! [D,H] :
      ( ( dog(D)
        & human(H)
        & H != owner_of(D)
        & bit(D,H) )
     => hates(H,owner_of(D)) ) ).

fof(jon_hates_another_human,conjecture,
    ? [H] :
      ( human(H)
      & H != jon
      & hates(jon,H) ) ).


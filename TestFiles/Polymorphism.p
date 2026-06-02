thf(bird_type,type,
    bird: $tType ).

thf(tweety_type,type,
    tweety: bird ).

%----Type constructors
thf(list_type,type,
    list: $tType > $tType ).

thf(map_type,type,
    map: $tType > $tType > $tType ).

%----Polymorphic symbols
thf(bird_lookup_type,type,
    bird_lookup: 
      !>[A: $tType,B: $tType] : ( ( map @ A @ B ) > A > B ) ).

thf(bird_update_type,type,
    bird_update: 
      ?*[A: $tType,B: $tType] : ( ( map @ A @ B ) > A > B > ( map @ A @ B ) ) ).

%----Use of polymorphic symbols
thf(bird_lookup_update_same,axiom,
    ! [RangeType: $tType,Map: map @ bird @ RangeType,Key: bird,Value: RangeType] :
      ( ( bird_lookup @ bird @ RangeType @ ( bird_update @ bird @ RangeType @ Map @ Key @ Value ) @ Key )
      = Value ) ).

%------------------------------------------------------------------------------

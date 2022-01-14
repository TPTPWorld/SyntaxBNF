tff(1,axiom,[.](youtoo)).
tff(1,axiom,<#1>(youtoo)).
tff(1,axiom,{$conn}(youtoo)).
tff(1,axiom,{$conn(#1)}(youtoo)).
tff(1,axiom,{$conn(#1,$foo:=abc,$blah:=qqq)}(youtoo)).
tff(1,axiom,{$conn($foo:=abc,#1,$blah:=qqq)}(youtoo)).
tff(1,axiom,{$$conn}(youtoo)).
tff(1,axiom,{$$conn(#1)}(youtoo)).
tff(1,axiom,{$$conn(#1,$$foo:=abc,$$blah:=qqq)}(youtoo)).
tff(1,axiom,{$$conn($$foo:=abc,#1,$$blah:=qqq)}(youtoo)).
thf(1,axiom,[.] @ youtoo).
thf(1,axiom,<#1> @ youtoo).
thf(1,axiom,{$conn} @ youtoo).
thf(1,axiom,{$conn(#1)} @ youtoo).
thf(1,axiom,{$conn(#1,$foo:=abc,$blah:=qqq)} @ youtoo).
thf(1,axiom,{$conn($foo:=abc,#1,$blah:=qqq)} @ youtoo).
thf(1,axiom,{$$conn} @ youtoo).
thf(1,axiom,{$$conn(#1)} @ youtoo).
thf(1,axiom,{$$conn(#1,$$foo:=abc,$$blah:=qqq)} @ youtoo).
thf(1,axiom,{$$conn($$foo:=abc,#1,$$blah:=qqq)} @ youtoo).

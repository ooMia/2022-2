father(a, b).
father(b, c).
father(c,d).
father(d,e).
father(e,f).
mother(ma,mb).
mother(mb,mc).
mother(mc,md).
mother(md,me).
mother(me,mf).
human(socrates).
human(plato).
fact(0,1).
fact(N,F) :- N>0, N1 is N-1, fact(N1,F1), F is N*F1.     % (,)
mortal(X) :- human(X).
male(X) :- father(X,_).              %  (_)
female(Y) :- mother(Y,_).
grandfather(X, Z) :- father(X,Y), father(Y,Z).
grandmother(X,Z) :- mother(X,Y), mother(Y,Z).
ancestor(X,Z) :- (father(X,Z) ; mother(X,Z)) ;           % (;)
      (father(X,Y); mother(X,Y)), ancestor(Y,Z).
descendant(X,Z) :- ancestor(Z,X).
son(X,Z) :- (father(Z,X);mother(Z,X)), male(X).
daughter(Y,Z) :- (mother(Z,Y);father(Z,Y)), female(Y).

.name	   "125"
.comment   "125 est un nombre de Friedman
			Les nombres de Friedman sont des nombres qui sont le resultat d'une combinaison de tout les chiffres les composant,
			125 est le cube de 5,
			125 est un nombre vraiment cool,
			Ne soyez pas hecatontakaiicosikaipentaphobe, mettez nous 125"

init:		fork %:forkexpand
			aff r1
			aff r2
			aff r3
			aff r4

fork:		live %125
			fork %:train
lforker:	live %125
forker:		fork %:lforker
train:		fork %:forkexup

			live %125
			fork %:forktrain
zork:		sti r1,%:zlive,%1
			ld %0,r2
			live %125
			fork %-5
zlive:		live %125
			zjmp %:zlive

forkexpand:	live %125
			fork %:forkexdo
forkexup:	live %125
			ld %-45,r3
			fork %:fork2u

fork1u:		fork %:expand2u
expand1u:	ld %0x0b540203,r2
			ld %0,r4
			ld %0,r5
			zjmp %:startu

expand2u:	ld %0x04010000,r2
			ld %4,r4
			ld %0,r5
			zjmp %:startu

fork2u:		fork %:expand4u
expand3u:	st r1,r2
			ld %6,r4
			ld %0,r5
			zjmp %:startu

expand4u:	ld %0x0009ffc9,r2
			ld %9,r4
			ld %0,r5
			zjmp %:startu

startu:		sti r2,%:init,r4
			live %125
			zjmp %:init

forktrain:	live %125
			ld %10,r3
			fork %:fork2t

fork1t:		ld %0,r5
			zjmp %:fork1d

fork2t:		ld %0,r5
			zjmp %:fork2d

forkexdo:	live %125
			ld %105,r3
			fork %:fork2d

fork1d:		fork %:expand2d
expand1d:	ld %0x0b540203,r2
			ld %0,r4
			ld %0,r5
			zjmp %:startd

expand2d:	ld %0x04010000,r2
			ld %4,r4
			ld %0,r5
			zjmp %:startd

fork2d:		fork %:expand4d
expand3d:	st r1,r2
			ld %6,r4
			ld %0,r5
			zjmp %:startd

expand4d:	ld %0x0009005f,r2
			ld %9,r4
			ld %0,r5
			zjmp %:startd

startd:		sti r2,r3,r4
			live %125
			zjmp %95

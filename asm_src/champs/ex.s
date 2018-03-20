.name	"zork"
.comment "t"just a basic living prog
		
l2:sti	 r16 	,	 %:live	, %0
	and	r1, :live , r1
live:	live %1
	zjmp	%:live

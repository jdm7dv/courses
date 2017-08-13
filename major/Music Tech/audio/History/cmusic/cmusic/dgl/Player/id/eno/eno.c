# define P_INTEGER
# include <carl/Player.h>
main()
{
	Pmain();
}






















typedef struct {
	char *mpu_reg_data;	
	char *mpu_reg_cmd; }
 MPU_REG;

int	key;

keydown()
{
	int	ch;

	if (nb_acia_read(0, &ch) != 0) {
		acia_write(0, ch);
		key = ch;
		return(TRUE); }
 else
		return(FALSE);

}


M_start() {
	trap_init();
	mpu_init();
	start_watch_pedal(0);

}


M_ter()
{
	stop_ptm();
		mpuwcmd(0xff,0);
	exit(0);

}


int ter;

Player
keytest(_x)
	Player *_x;
{ if(_x->icode==0){
		ter = 0;
		Wait_for(keydown, CONTINUOUS);
		Return;

	}


	switch (key) {
		case '.':
			ter = 1;
			Kill(Self);
			Return;
		default:
			acia_write(0, key);
			break;
}


	return(*_x);


}struct note {
 int sequence; int key, chan;
};


Player
note(_x)
	Player *_x;
{
	int vel, next;

	switch (((struct note *)_x->nstnc)->sequence) {
		case 0:
			((struct note *)_x->nstnc)->chan = _x->pn[5];
			((struct note *)_x->nstnc)->key = _x->pn[6];
			vel = _x->pn[7];
			note_on(((struct note *)_x->nstnc)->chan, ((struct note *)_x->nstnc)->key, vel);
			next = Now + _x->pn[4];
			Wait_until(next);
			((struct note *)_x->nstnc)->sequence = 1;
			break;
		case 1:
			note_off(((struct note *)_x->nstnc)->chan, ((struct note *)_x->nstnc)->key);
			Kill(Self);
			break;
}


	return(*_x);


}

typedef Player * Pptr;struct track {
 int	dur, chan, key, vel;
};




Player
track(_x)
	Player *_x; 
{
	Pptr	v;

	if (ter) {
		Kill(Self);
		Return;

	}


	if ((v = New_player(note, Now, -1, P_READY)) == 0) {
		fprintf(0, "New_player failed\n");
		exit(1);
	}

	((struct track *)_x->nstnc)->dur = Rand() % 4000 + 50;
	((struct track *)_x->nstnc)->chan = _x->pn[1];
	((struct track *)_x->nstnc)->key = Rand() % 64 + 32;
	((struct track *)_x->nstnc)->vel = Rand() % 64 + 32;
	Set_p(v, 4, ((struct track *)_x->nstnc)->dur);
	Set_p(v, 5, ((struct track *)_x->nstnc)->chan);
	Set_p(v, 6, ((struct track *)_x->nstnc)->key);
	Set_p(v, 7, ((struct track *)_x->nstnc)->vel);
	Join(ALL_CHILDREN);


	return(*_x);



}struct agent {
 	Pptr 		v1, v2;
};



Player
agent(_x)
	Player *_x;
{

	if ((((struct agent *)_x->nstnc)->v1 = New_player(track, Now, -1, P_READY)) == 0) {
		fprintf(0, "New_player failed\n");
		exit(1);
	}

	Set_p(((struct agent *)_x->nstnc)->v1, 1L, 0L);
	if ((((struct agent *)_x->nstnc)->v2 = New_player(track, Now, -1, P_READY)) == 0) {
		fprintf(0, "New_player failed\n");
		exit(1);
	}

	Set_p(((struct agent *)_x->nstnc)->v2, 1L, 1L);
	Kill(Self);

	return(*_x);


}

outstr(str)
	char *str;
{
	register char	*c = str;

	while (*c != '\0') {
		if (*c == '\n')
			acia_write(1, '\r');
		acia_write(1, *c++);
}
}

/* initialize Player instance */
PI_keytest(i, c)
	Player *i, *c;
{
	i->cproc = c->cproc;
	i->iproc = c->iproc;
	i->name = c->name;
	i->hipn = c->hipn;
	i->plen = c->plen;
}
/* initialize Player instance */
PI_note(i, c)
	Player *i, *c;
{
	i->cproc = c->cproc;
	i->iproc = c->iproc;
	i->name = c->name;
	i->hipn = c->hipn;
	i->plen = c->plen;
	i->pn=(long *) calloc(8, (unsigned) sizeof(long));
	i->ps=(char **)calloc(8, (unsigned) sizeof(char *));
	i->pp=(char **)calloc(8, (unsigned) sizeof(char *));
	i->nstnc=(char *)calloc(1, (unsigned) sizeof(struct note));
}
/* initialize Player instance */
PI_track(i, c)
	Player *i, *c;
{
	i->cproc = c->cproc;
	i->iproc = c->iproc;
	i->name = c->name;
	i->hipn = c->hipn;
	i->plen = c->plen;
	i->pn=(long *) calloc(2, (unsigned) sizeof(long));
	i->ps=(char **)calloc(2, (unsigned) sizeof(char *));
	i->pp=(char **)calloc(2, (unsigned) sizeof(char *));
	i->nstnc=(char *)calloc(1, (unsigned) sizeof(struct track));
}
/* initialize Player instance */
PI_agent(i, c)
	Player *i, *c;
{
	i->cproc = c->cproc;
	i->iproc = c->iproc;
	i->name = c->name;
	i->hipn = c->hipn;
	i->plen = c->plen;
	i->nstnc=(char *)calloc(1, (unsigned) sizeof(struct agent));
}
/* make Player class template */
PC_keytest(c)
	Player *c;
{
	c->cproc = keytest;
	c->iproc = PI_keytest;
	c->name = "keytest";
	c->hipn = c->plen = 0;
	if (install((char *) c->cproc, AT_CLASS, (char *) c) == NULL)
		exit(255);
	if(install(c->name, AT_STR_CLASS, (char *) c) == NULL)
		exit(255);
}
/* make Player class template */
PC_note(c)
	Player *c;
{
	c->cproc = note;
	c->iproc = PI_note;
	c->name = "note";
	c->hipn = c->plen = 7;
	if (install((char *) c->cproc, AT_CLASS, (char *) c) == NULL)
		exit(255);
	if(install(c->name, AT_STR_CLASS, (char *) c) == NULL)
		exit(255);
}
/* make Player class template */
PC_track(c)
	Player *c;
{
	c->cproc = track;
	c->iproc = PI_track;
	c->name = "track";
	c->hipn = c->plen = 1;
	if (install((char *) c->cproc, AT_CLASS, (char *) c) == NULL)
		exit(255);
	if(install(c->name, AT_STR_CLASS, (char *) c) == NULL)
		exit(255);
}
/* make Player class template */
PC_agent(c)
	Player *c;
{
	c->cproc = agent;
	c->iproc = PI_agent;
	c->name = "agent";
	c->hipn = c->plen = 0;
	if (install((char *) c->cproc, AT_CLASS, (char *) c) == NULL)
		exit(255);
	if(install(c->name, AT_STR_CLASS, (char *) c) == NULL)
		exit(255);
}
/* preset Player instances */
PP_keytest(i, c)
	Player *i, *c;
{
	PI_keytest(i, c);
	i->beg	= (long) 0;
	i->ptime	= (long) 0;
	i->dur	= (long) -1L;
	i->runstat	= P_READY;
	set_wait(i, i->ptime);
}
/* preset Player instances */
PP_agent(i, c)
	Player *i, *c;
{
	PI_agent(i, c);
	i->beg	= (long) 0;
	i->ptime	= (long) 0;
	i->dur	= (long) -1L;
	i->runstat	= P_READY;
	set_wait(i, i->ptime);
}
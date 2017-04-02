#include <stdio.h>

int main()
{
	int note, i;
	printf_s("Please enter the key (in pitch-class number, 0-11): ");
	scanf_s("%d", &note);
	/* make sure start note is non negitive*/
	while (note < 0) note += 12;
	{
		/*build the scale*/
		for (i = 0; i < 7; i++)
		{
			/* translate pitch class to note name*/
			if (note % 12 == 0) 
			{
				printf_s("C ");
			}
			else if (note % 12 ==1) 
			{
				printf_s("Db ");
			}
			else if (note % 12 == 2)
			{
				printf_s("D ");
			}
			else if (note % 12 == 3)
			{
				printf_s("Eb ");
			}
			else if (note % 12 == 4)
			{
				printf_s("E ");
			}
			else if (note % 12 == 5)
			{
				printf_s("F ");
			}
			else if (note % 12 == 6)
			{
				printf_s("Gb ");
			}
			else if (note % 12 == 7)
			{
				printf_s("G ");
			}
			else if (note % 12 == 8)
			{
				printf_s("Ab ");
			}
			else if (note % 12 == 9)
			{
				printf_s("A ");
			}
			else if (note % 12 == 10)
			{
				printf_s("Bb ");
			}
			else
			{
				printf_s("B");
			}
			/*find the next ptich class jump a semitone only after a 3rd step*/
			if (i != 2)
			{
				note += 2;
			}
			else 
			{
				note++;
			}
		}

	}
	printf_s("/n");
	return 0;
	
}
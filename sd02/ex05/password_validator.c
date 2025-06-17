#include "password_validator.h"
#include <stdbool.h>
#include <stdio.h>

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
	bool isupper = false;
	bool islower = false;
	bool isdigit = false;
	bool isnotequal = false;
	bool special = false;
	int len = 0;
	const char specials[9] = "@#$%^&*";

	while (*new_pw)
	{
		if (*new_pw >= 'A' && *new_pw <= 'Z')
			isupper = true;
		else if (*new_pw >= 'a' && *new_pw <= 'z')
			islower = true;
        // Controllo numeri
        else if (*new_pw >= '0' && *new_pw <= '9')
			isdigit = true;
        // Controllo caratteri speciali
        else
		{
            const char *s = specials;
            while (*s)
			{
                if (*new_pw == *s)
				{
                    special = true;
                    break;
                }
                s++;
            }
        }
		if (*new_pw != *curr_pw++)
			isnotequal = true;
		++len;
		new_pw++;
	}
	//	printf("len: %d\n",len);
	//	printf("upp: %d\n",isupper);
	//	printf("low: %d\n",islower);
	//	printf("digit: %d\n",isdigit);
	//	printf("equal: %d\n",isnotequal);
	//	printf("special: %d\n",special);
	if((len < 8) || isupper == false || islower == false || isdigit == false || isnotequal == false || special == false)
		return INVALID;
	return VALID;
}
//
//
//#include <stdio.h>
//
//int main() {
//    char new_pw[100];
//    char curr_pw[100];
//    PwStatus result;
//
//    // Input utente
//    printf("Inserisci nuova password: ");
//    scanf("%99s", new_pw);
//    
//    printf("Inserisci password corrente: ");
//    scanf("%99s", curr_pw);
//
//    // Validazione
//    result = validate_password(new_pw, curr_pw);
//
//    // Risultato
//    if (result == VALID) {
//        printf("VALID: Password accettabile\n");
//    } else {
//        printf("INVALID: Password rifiutata\n");
//    }
//
//    return 0;
//}

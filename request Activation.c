


int main(){
    FILE *fp;
    char promptUsercode[20];
    char usercode, status, assignmentUrl, attemptsUrl;

    fp = fopen(".\\../textfiles/pupils.txt", "r");

    printf("Please enter your usercode\n");
    scanf("%s", promptUsercode);
    while (fscanf(fp, "%s %s %s %s", usercode, status, assignmentUrl, attemptsUrl) > 0)
    {

        // start comparing the usercodes
        if (strcmp(usercode, promptUsercode) == 0)
        {

            int alreadyRequested = 0;
            // check if the user had already submitted their request
            if (strcmp(status, "activated") == 1)
            {
                /// Reqesut for activatation
                printf("You are currently deactivated\n");
                printf("Enter:\n1.For activation\n.0 to exit\n");
                scanf("%d", &activationRequest);
                if (activationRequest == 1)
                {
                    // add the usercode the request file list
                    ReqfpRead = fopen("./activation/requests.txt", "r");
                    /// the request was sent already
                    while (fscanf(ReqfpRead, "%s", storedUsercode) > 0)
                    {

                        if (strcmp(usercode, storedUsercode) == 0)
                        {
                            alreadyRequested = 1;
                        }
                    }
                    if (alreadyRequested == 1)
                    {
                        printf("Previously your request was sent successfully\n");
                        printf("Try again within the next 24hours\n");
                        printf("Thanks management\n");
                        fclose(ReqfpRead);
                    }
                    else
                    {
                        ReqfpAdd = fopen("./activation/requests.txt", "a+");
                        strncat(usercode, "\n", 2);
                        fprintf(ReqfpAdd, usercode);
                        printf(".......activation request sent successfully\n");
                        printf("Try again within 24hours when the teacher has activated you\n");
                        printf("Thanks management\n");

                        fclose(ReqfpAdd);
                    }
                    cont = 1;
                }
            }
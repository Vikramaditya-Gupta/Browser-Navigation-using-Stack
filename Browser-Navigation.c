#include<stdio.h>
#include<string.h>

int maxsize = 50;

char backStack[50][100];
char forwardStack[50][100];

int backTop = -1;
int forwardTop = -1;

int pushBack(char page[])
{
    if(backTop == maxsize - 1)
    {
        printf("Back Stack is Full\n");
    }
    else
    {
        backTop++;
        strcpy(backStack[backTop], page);
    }
}

int pushForward(char page[])
{
    if(forwardTop == maxsize - 1)
    {
        printf("Forward Stack is Full\n");
    }
    else
    {
        forwardTop++;
        strcpy(forwardStack[forwardTop], page);
    }
}

int popBack()
{
    if(backTop == -1)
    {
        printf("Back Stack is Empty\n");
        return 0;
    }
    else
    {
        backTop--;
        return 1;
    }
}

int popForward()
{
    if(forwardTop == -1)
    {
        printf("Forward Stack is Empty\n");
        return 0;
    }
    else
    {
        forwardTop--;
        return 1;
    }
}

int displayBack()
{
    if(backTop == -1)
    {
        printf("Back Stack is Empty\n");
    }
    else
    {
        printf("\nBack History:\n");

        for(int i = backTop; i >= 0; i--)
        {
            printf("| %s |\n", backStack[i]);
            printf(" ____ \n");
        }
    }
}

int displayForward()
{
    if(forwardTop == -1)
    {
        printf("Forward Stack is Empty\n");
    }
    else
    {
        printf("\nForward History:\n");

        for(int i = forwardTop; i >= 0; i--)
        {
            printf("| %s |\n", forwardStack[i]);
            printf(" ____ \n");
        }
    }
}

int main()
{
    char currentPage[100] = "Home";
    char page[100];

    int k;

    while(1)
    {
        printf("\n\n========== Browser Navigation ==========\n");
        printf("Current Page: %s\n", currentPage);

        printf("\nSelect Browser Operation:\n");
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display Back History\n");
        printf("5. Display Forward History\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&k);

        switch(k)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%s",page);

                // Current page goes into Back Stack
                pushBack(currentPage);

                // Visit new page
                strcpy(currentPage,page);

                // Forward history is cleared
                forwardTop = -1;

                printf("Visited page: %s\n",currentPage);
                break;

            case 2:
                if(backTop == -1)
                {
                    printf("No previous page available\n");
                }
                else
                {
                    // Current page goes into Forward Stack
                    pushForward(currentPage);

                    // Previous page becomes current page
                    strcpy(currentPage,backStack[backTop]);

                    popBack();

                    printf("Moved Back to: %s\n",currentPage);
                }
                break;

            case 3:
                if(forwardTop == -1)
                {
                    printf("No forward page available\n");
                }
                else
                {
                    // Current page goes into Back Stack
                    pushBack(currentPage);

                    // Forward page becomes current page
                    strcpy(currentPage,forwardStack[forwardTop]);

                    popForward();

                    printf("Moved Forward to: %s\n",currentPage);
                }
                break;

            case 4:
                displayBack();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
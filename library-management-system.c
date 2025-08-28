

#include <stdio.h>
#include <string.h>

int main()
{
    // Array variables for information
    char bookTitles[5][100];
    char bookAuthors[5][100];
    char bookGenres[5][100];

    // Define pointer
    char *titlePointer, *authorPointer, *genrePointer;

    int bookCount = 0;     // Track boos when added
    char choice;           // Menu choice
    char searchTitle[100]; // Input for book searching by title
    int found = 0;         // Indicator if book was found.

    do
    {
        // Display options  menu

        printf("Menu :\n");
        printf("a. Add a new book\n");
        printf("b.View all books\n");
        printf("c.Search for a book\n");
        printf("y. Exit\n");

        printf("\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        if (choice == 'a') // Add new book
        {
            if (bookCount >= 5)
            {
                printf("Book Limited reached! Cannot add more books.\n");
                continue;
            }
            getchar(); // Clear new line

            // Use pointers  to reference the current book
            titlePointer = bookTitles[bookCount];
            authorPointer = bookAuthors[bookCount];
            genrePointer = bookGenres[bookCount];

            // Input book details using pointers

            printf("Enter the book title: ");
            scanf(" %[^\n]", titlePointer);
            getchar();

            printf("Enter the author name: ");
            scanf(" %[^\n]", authorPointer);
            getchar();

            printf("Enter the book genre: ");
            scanf(" %[^\n]", genrePointer);
            getchar();

            printf("\n");

            printf("Book added successfully\n");
            bookCount++;

            printf("\n");
        }
        else if (choice == 'b')
        {
            if (bookCount == 0)
            {
                printf("No books in the library yet. \n");
            }
            else
            {
                printf("Books in the Library: \n");
                for (int i = 0; i < bookCount; i++)
                {

                    // pointer-style access to each field
                    titlePointer = bookTitles[i];
                    authorPointer = bookAuthors[i];
                    genrePointer = bookGenres[i];

                    printf("%d. Title: %s, Author: %s, Genre: %s", i + 1, titlePointer, authorPointer, genrePointer);
                }
            }
        }
        else if (choice == 'c')
        {
            if (bookCount == 0)
            {
                printf("No Books in the library yet.\n");
                continue;
            }
            getchar();
            printf("Enter the book title to search: ");
            scanf(" %[^\n]", searchTitle);
            found = 0;

            printf("\n");
            for (int i = 0; i < bookCount; i++)
            {

                // User pointer to accesss title for comparison
                titlePointer = bookTitles[i];

                if (strcmp(searchTitle, titlePointer) == 0)
                {
                    printf("Book found!\n");
                    printf("Title: %s\n", bookTitles[i]);
                    printf("Author: %s\n", bookAuthors[i]);
                    printf("Genre: %s", bookGenres[i]);

                    printf("\n");
                    found = 1;
                    break;
                }
            }
            printf("\n");
            if (!found)
            {
                printf("Book not found. \n");
            }
        }
        else if (choice == 'y')
        {
            printf("Exiting the program.");
        }
        else
        {
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 'y');

    return 0;
}

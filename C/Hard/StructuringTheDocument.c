#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// Start of the Answer ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct document get_document(char* text) {
    struct document Doc;
    int paragraph_count = 0, sentence_count = 0, word_count = 0, i = 0, word_length;
    int paragraph_index = 0, sentence_index = 0, word_index = 0;
    char buffer[20];

    /* Slicing document to paragraphs */
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '\n')
            paragraph_count++;
    }
    Doc.paragraph_count = paragraph_count + 1;
    Doc.data = (struct paragraph*)malloc(sizeof(struct paragraph) * (paragraph_count + 1));
    
    /* Slicing paragraph to sentences */
    for (i = 0; i < strlen(text)+1;  i++)
    {
        if (text[i] == '.')
            sentence_count++;
        if (text[i] == '\n' || text[i] == 0)
        {
            Doc.data[paragraph_index].sentence_count = sentence_count;
            Doc.data[paragraph_index].data = (struct sentence*)malloc(sizeof(struct sentence) * sentence_count);
            sentence_count = 0;
            paragraph_index++;
        }
    }

    /* Slicing Sentences to Words */
    paragraph_index = 0;
    for (i = 0; i < strlen(text);  i++)
    {
        if (text[i] == ' ')
            word_count++;
        if (text[i] == '.')
        {
            word_count++;
            Doc.data[paragraph_index].data[sentence_index].word_count = word_count;
            Doc.data[paragraph_index].data[sentence_index].data = (struct word*)malloc(sizeof(struct word) * word_count);
            sentence_index++;
            word_count = 0;
        }
        if (text[i] == '\n')
        {
            paragraph_index++;
            sentence_index = 0;
        }
    }
    
    // Converting the text into document
    i = 0;
    paragraph_index = 0;
    while (text[i] != 0)
    {
        sentence_index = 0;
        while (text[i] != '\n' && text[i] != 0)
        {// New paragraph
            word_index = 0;
            while (text[i] != '.')
            {// New sentence 
                word_length = 0;
                // Read Word into buffer
                while (text[i] != ' ' && text[i] != '.')
                {
                    buffer[word_length] = text[i];
                    i++;
                    word_length++;
                }
                buffer[word_length] = '\0';
                
                Doc.data[paragraph_index].data[sentence_index].data[word_index].data = (char*)malloc(word_length);
                // Copy the buffer into word in the document
                for (int k = 0; k < word_length+1; k++)
                {
                    Doc.data[paragraph_index].data[sentence_index].data[word_index].data[k] = buffer[k];
                }

                // increment indeices
                if (text[i] != '.')
                    i++;
                word_index++;
            }
            if (text[i] != '\n')
                i++;
            sentence_index++;
        }
        if (text[i] != 0)
            i++;
        paragraph_index++;
    }
    return Doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// End of the Answer /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for (int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for (int i = 0; i < para.sentence_count; i++) {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for (int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main()
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}

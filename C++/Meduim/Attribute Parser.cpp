#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tag
{
    string name;
    vector<tag*> children;

    int attributeCount;
    string* attributeName;
    string* attributeValue;
    
    bool status;
    bool childStatus;
}Tag;

/* Status */
#define OPENED  false
#define CLOSED  true
/* Child Status */
#define PARENT  false
#define CHILD   true

vector<Tag> readTags(int N);
string evaluateQuery(vector<Tag> tags, string line);

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<Tag> tags = readTags(N);

    while(Q--)
    {
        string line;
        cin >> line;
        cout << evaluateQuery(tags, line) << endl;
    }
    
    return 0;
}

vector<Tag> readTags(int N)
{
    vector<Tag> tags(N/2);
    int tagIndex = 0;
    int openTags = 0;

    while (N--)
    {
        string line[50];
        int attributesCount;
        for(int i = 0; i < 50; i++){
            cin >> line[i];
            int n = line[i].size();
            if(line[i][n-1] == '>'){
                attributesCount = i/3;
                line[i].erase(line[i].end() - 1);
                break;
            }
        }

        if(line[0][1] == '/')
        {
            // Remove </ 
            line[0].erase(line[0].begin());
            line[0].erase(line[0].begin());

            // Search for the tag to close it
            for(int i = 0; i < tagIndex; i++){
                if(tags[i].name == line[0]){
                    tags[i].status = CLOSED;
                    break;
                }
            }
            openTags--;
        }
        else
        {
            /* Initialize the tag */
            line[0].erase(line[0].begin()); // remove <
            tags[tagIndex].name = line[0];
            
            tags[tagIndex].attributeCount = attributesCount;
            tags[tagIndex].attributeName = new string[tags[tagIndex].attributeCount];
            tags[tagIndex].attributeValue = new string[tags[tagIndex].attributeCount];
            
            tags[tagIndex].status = OPENED;
            if(openTags == 0)
                tags[tagIndex].childStatus = PARENT;
            else
                tags[tagIndex].childStatus = CHILD;

            /* Assign attributes of the tag */
            for(int i = 0; i < attributesCount; i++){
                tags[tagIndex].attributeName[i] = line[(i*3) + 1];
                // remove ""
                line[(i*3) + 3].erase(line[(i*3) + 3].end() - 1); 
                line[(i*3) + 3].erase(line[(i*3) + 3].begin());
                
                tags[tagIndex].attributeValue[i] = line[(i*3) + 3];
            }

            /* Child */
            for(int i = tagIndex - 1; i >= 0; i--)
            {
                if(tags[i].status == OPENED){
                    tags[i].children.push_back(&tags[tagIndex]);
                    break;
                }
            }
            tagIndex++;
            openTags++;
        }
        
    }
    return tags;
}

string evaluateQuery(vector<Tag> tags, string line)
{
    int index = 0;
    string result = "Not Found!";

    string tagName;
    while(line[index] != '.' && line[index] != '~')
        tagName.push_back(line[index++]);
    
    Tag* currentTag;
    for(int i = 0; i < (int)tags.size(); i++){
        if(tags[i].name == tagName){
            currentTag = &tags[i];
            break;
        }
    }

    if(currentTag->childStatus == PARENT)
    {
        bool child;
        if(line[index] == '.')
            child = true;
        else if(line[index] == '~')
            child = false;

        bool found = true;
        index++;
        
        if(child)
        {
            tagName.clear();
            while (1)
            {
                if(line[index] == '~'){
                    found = false;
                    for(int i = 0; i < (int)currentTag->children.size(); i++){
                        if(currentTag->children[i]->name == tagName){
                            found = true;
                            currentTag = currentTag->children[i];
                            break;
                        }
                    }
                    break;
                }
                else if(line[index] == '.'){
                    found = false;
                    for(int i = 0; i < (int)currentTag->children.size(); i++){
                        if(currentTag->children[i]->name == tagName){
                            found = true;
                            currentTag = currentTag->children[i];
                            break;
                        }
                    }
                    if(!found)
                        break;
                    tagName.clear();
                }
                else{
                    tagName.push_back(line[index]);
                }
                index++;
            }
            index++;
        }    
        
        if(found)
        {
            string attName;
            for(int i = index; i < (int)line.size(); i++)
                attName.push_back(line[i]);

            for(int i = 0; i < currentTag->attributeCount; i++){
                if(currentTag->attributeName[i] == attName){
                    result = currentTag->attributeValue[i];
                    break;
                }
            }
        }
    }

    return result;
}

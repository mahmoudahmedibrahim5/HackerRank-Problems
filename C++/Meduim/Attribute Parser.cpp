#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct 
{
    string name;
    void* child;
    int attributeCount;
    string* attributeName;
    string* attributeValue;
    bool status;
    bool childStatus;
}Tag;

#define OPENED  false
#define CLOSED  true

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<Tag> tags(N/2);
    int tagIndex = 0;
    while (N--)
    {
        string line[50];
        int attributesCount;
        for(int i = 0; i < 50; i++){
            cin >> line[i];
            int n = line[i].size();
            if(line[i][n-1] == '>'){
                attributesCount = i;
                break;
            }
        }

        if(line[0][1] == '/')
        {
            line[0].erase(line[0].begin());
            line[0].erase(line[0].begin());
            line[0].erase(line[0].end()-1);

            for(int i = 0; i < tagIndex; i++){
                if(tags[i].name == line[0]){
                    tags[i].status = CLOSED;
                    break;
                }
            }
        }
        else
        {
            /* Initialize the tag */
            line[0].erase(line[0].begin());
            if(attributesCount == 1)
                line[0].erase(line[0].end() - 1);
            tags[tagIndex].name = line[0];
            tags[tagIndex].attributeCount = attributesCount/3;
            tags[tagIndex].attributeName = new string[tags[tagIndex].attributeCount];
            tags[tagIndex].attributeValue = new string[tags[tagIndex].attributeCount];
            tags[tagIndex].status = OPENED;
            tags[tagIndex-1].childStatus = false;

            /* Assign attributes of the tag */
            for(int i = 0; i < attributesCount/3; i++){
                tags[tagIndex].attributeName[i] = line[(i*3) + 1];
                line[(i*3) + 3].erase(line[(i*3) + 3].end() - 1);
                line[(i*3) + 3].erase(line[(i*3) + 3].begin());
                tags[tagIndex].attributeValue[i] = line[(i*3) + 3];
            }
            tags[tagIndex].attributeValue[tags[tagIndex].attributeCount - 1].erase(tags[tagIndex].attributeValue[tags[tagIndex].attributeCount - 1].end()-1);

            /* Child */
            if(tagIndex > 0){
                if(tags[tagIndex-1].status == OPENED){
                    tags[tagIndex-1].child = (void *)&tags[tagIndex];
                    tags[tagIndex-1].childStatus = true;
                }
            }

            tagIndex++;
        }
        
    }

    int index = 0;
    while(Q--)
    {
        index = 0;

        string line;
        cin >> line;

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

        bool child;
        if(line[index] == '.'){
            child = true;
            currentTag = (Tag *)currentTag->child;
        }
        else if(line[index] == '~')
            child = false;
        else
            cout << "Error" << endl << "Error" << endl << "Error" << endl;

        bool found = true;
        if(child)
        {
            tagName.clear();
            while (child)
            {
                index++;
                if(line[index] == '~'){
                    break;
                }
                else if(line[index] == '.'){
                    //currentTag = (Tag *)currentTag->child;
                    tagName.clear();
                }
                else{
                    tagName.push_back(line[index]);
                }
            }
            index++;
            
            found = false;
            for(int i = 0; i < (int)tags.size(); i++){
                if(tags[i].name == tagName){
                    currentTag = &tags[i];
                    found = true;
                    break;
                }
            }
        }
        else
            index++;
            
        string result = "Not Found!";
        if(!found){

        }
        else{
            string attName;
            for(int i = index; i < (int)line.size(); i++){
                attName.push_back(line[i]);
            }
            // cout << attName << endl;
            // cout << currentTag->name << endl;

            
            for(int i = 0; i < currentTag->attributeCount; i++){
                if(currentTag->attributeName[i] == attName){
                    result = currentTag->attributeValue[i];
                    break;
                }
            }
        }
        cout << result << endl;
    }

    // cout << endl;
    // cout << "/************** Tags View **************/" << endl;
    // for(int i = 0; i < (int)tags.size(); i++){
    //     cout << tags[i].name << endl;
    //     cout << "attributes count = " << tags[i].attributeCount << endl;
    //     for(int j = 0; j < tags[i].attributeCount; j++){
    //         cout << "attribute name = " << tags[i].attributeName[j] << ", and its value = " << tags[i].attributeValue[j] << endl;
    //     }
    //     cout << "Status = " << tags[i].status << endl << endl;
    //     cout << "Childs status = " << tags[i].childStatus << endl << endl;
    // }
    

    return 0;
}

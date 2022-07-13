#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct atrribute { 
    string name, value; 
}; 

//each line of the HRML markup lang
class tag { 
        
    public: 
        string tag_name;        //tag name
        int position;           //to determine offsprings of mother tag
        atrribute tag_attrribute;   //struct holding tag name & value 
        vector<atrribute> tag_attr;    //vector of attribute structs 
        //vector<tag> tag_vector; 

        void set_name(string name) { 
            tag_name = name;
        }

        void set_position(int n) { 
            position = n; 
        }

        //set a new attribute with name and value
        void set_attr(string name, string val) { 
           tag_attrribute.name = name; //watch for err
           tag_attrribute.value = val;  
        }

        //add a new attribute to attribute vector
        void add_attr(atrribute nw_attr) { 
            tag_attr.push_back(nw_attr); 
        }

        /*void addTag(tag newChild) { 
            tag_vector.push_back(newChild); 
        }*/


}; 


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    //add tags to this vector
    vector<tag> tag_vector; 

    //get N & Q 
    int N, Q; 
    cin >> N >> Q; 

    string t_name, attr_name, sign, attr_val; 
   
    //parse all the lines of the HRML source program
    for(int i=0; i<N; i++) { 

        cout << "in the for loop" << endl ;
        cin >> t_name; 

        //we have reached the closing tags 
        if(t_name.find('/') != string::npos) {       //the char '/' is in the string
            //we want to reach the query so keep going
            cout << "skipped this turn" << endl; 
            continue; 
        }
        
        cin >> attr_name >> sign >> attr_val; 
        
        //not a closing tag, make a new tag object 
        tag newTag; 

        //manipulate strings, remove opening bracket
        t_name = t_name.substr(1, -1);
        //attr_val = attr_val.substr(1, -2);  

        newTag.set_name(t_name);
        newTag.set_position(i+1); 

        //the tag has attributes and we have not reached the closing bracket
        while(attr_val.find('>') == string::npos) {     //there is no bracket in the attr_val 
            cout << "first line of the while loop" << endl;
            attr_val = attr_val.substr(1, attr_val.size()-2);          //remove useless chars from attr_val 
            newTag.set_attr(attr_name, attr_val); 
            newTag.add_attr(newTag.tag_attrribute);
           
            cin >> attr_name >> sign >> attr_val;       //get the next attr_name & val
            cout << "last line of the while loop" << endl; 
        }

        cout << "exited the while loop" << endl; 
        //for the last attribute
        attr_val = attr_val.substr(1, attr_val.size()-3);  
        newTag.set_attr(attr_name, attr_val); 
        newTag.add_attr(newTag.tag_attrribute);

        cout << t_name << " " << attr_name << " " << sign << " " << attr_val << endl; 

        //we have reached the end of the tag 
        //add the tag to the tag vector 
        tag_vector.push_back(newTag);        //newTag.addTag(newTag); 
        cout << "i: " << i << endl; 
    
    }
    cout << "exited the for loop" << endl; 

    //code testing 
    for(int i=0; i<tag_vector.size(); i++) { 
        cout << "tag_name: " << tag_vector[i].tag_name << endl; 
        cout << "pos: " << tag_vector[i].position << endl; 

        for(int j=0; j<tag_vector[i].tag_attr.size(); j++) { 
            cout << "attribute-name: " << tag_vector[i].tag_attr[j].name <<endl; 
            cout << "attribute-value: " << tag_vector[i].tag_attr[j].value <<endl;
        }

    }

    //parsing the query     
    string query, tg_name, tg_attr; 
    int tag_pos;     
    for(int i=0; i<Q; i++) {
        cin >> query; 

        //check first if the query requests a nested atrribute
        size_t find_dot = query.find('.'); 
        
        while(find_dot != string::npos) {
            tg_name = query.substr(0, find_dot-1); 

            //check if it is a valid & store pos
            for(int i=0; i<tag_vector.size(); i++) {
                if(tg_name == tag_vector[i].tag_name)  {
                    int tag_pos = tag_vector[i].position; 
                }
            }

            if(tag_pos > tag_vector[i].position) {  //if they are notin proper nested order 
                return;                           //hoping it will skip out of the while loop 
            }

            query = query.substr(find_dot+1, query.size()); 
            find_dot = query.find('.'); 

        }

        size_t find_tilde = query.find('~'); 
        tg_name = query.substr(0, find_tilde-1); 
        tg_attr = query.substr(find_tilde+1, query.size());

        

    }

  


    return 0;
}

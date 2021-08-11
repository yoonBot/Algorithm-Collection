/* Vector Implementation
 * @author yoonbot
 * 08/11/2021
 */

#include <iostream>
#include <vector>
using namespace std;

/* Additional functions used */
void menu();

/* Driver Code */
int main(){
    vector<int> v;
    int menuInput, run, input, index, val, size, flag;
    
    menu();
    cout << "Enter menu : ";
    cin >> menuInput;
    while (menuInput != 13){
        switch(menuInput){

            // Push
            case 1:
                cout << "How many numbers to push?: ";
                cin >> run;
                for (int i = 0; i < run; i++){
                    cin >> input;
                    v.push_back(input);
                }
                break;
            
            // Insert
            case 2: 
                cout << "Enter value to be entered: ";
                cin >> val;
                cout << "Enter position for the value: ";
                cin >> index;
                v.insert(index, val);
                break;

            // Pop
            case 3:
                v.pop_back();
                cout << "Last element has been poped!\n";
                break;
            
            // Erase
            case 4: 
                cout << "Which element would you like to erase?: ";
                cin >> val;
                for (auto i = v.begin(); i != v.end(); ++i)
                    if (*i == val){
                        v.erase(i);
                        i--;
                        flag = 1;
                    }
                if (flag == 0) cout << "Failed to locate value " << val << "\n";
                break;
            
            // Assign
            case 5:
                cout << "Enter value to be inserted: ";
                cin >> val;
                cout << "Enter size/range of the vector to be replaced: ";
                cin >> index;
                v.assign(index, val);
                break;

            // Clear
            case 6:
                v.clear();
                cout << "Erased all of the contents in the vector\n";
                break;
            
            // Emplace
            case 7:
                cout << "Enter position to emplace: ";
                cin >> index;
                cout << "Enter value to be emplaced at that position: ";
                cin >> val;
                v.emplace(v.begin() + index, val);
                cout << val << " emplaced at position " << index << "\n";
                break;

            // Emplace back
            case 8: 
                cout << "Enter value to be emplaced at the rear\n";
                cin >> val;
                v.__emplace_back(val);
                cout << val << " emplaced at the rear\n";
                break;
            
            // Resize vector
            case 9:
                cout << "Enter new vector size: ";
                cin >> size;
                v.resize(size);
                cout << "Vector has been resized to size " << size << "\n";
                break;

            // Shrink
            case 10:
                v.shrink_to_fit();
                cout << "Vector has shrunk to fit size " << v.size() << "\n";
                break;
            
            // Find array value
            case 11:
                cout << "Enter index to find value: ";
                cin >> index;
                cout << "Value at index " << index << " is " << v.at(index) << "\n";
                break;

            // Print vector info 
            case 12:
                if (v.empty() == false){
                    cout << "Output of begin and end: ";
                        for (auto i = v.begin(); i != v.end(); ++i)
                            cout << *i << " ";

                    cout << "\nOutput of cbegin and cend: ";
                        for (auto i = v.cbegin(); i != v.cend(); ++i)
                            cout << *i << " ";

                    cout << "\nOutput of rbegin and rend: ";
                        for (auto i = v.rbegin(); i != v.rend(); ++i)
                            cout << *i << " ";

                    cout << "\nOutput of crbegin and crend: ";
                        for (auto i = v.crbegin(); i != v.crend(); ++i)
                            cout << *i << " ";
                    cout << "\nInfo\n";
                    cout << "Front: " << v.front() << "\n";
                    cout << "Back: " << v.back() << "\n";
                    cout << "Size: " << v.size() << "\n";
                    cout << "Capacity: " << v.capacity() << "\n";
                    cout << "Max Size: " << v.max_size() << "\n";

                }
                else
                    cout << "Vector is empty!\n";

                break;

        }
    }

    return 0;
}

void menu(){
    cout << "___MENU___\n";
    cout << "1. Push\n";
    cout << "2. Insert\n";
    cout << "3. Pop\n";
    cout << "4. Erase\n";
    cout << "5. Assign\n";
    cout << "6. Clear\n";
    cout << "7. Emplace\n";
    cout << "8. Emplace back\n";
    cout << "9. Resize\n";
    cout << "10. Shrink\n";
    cout << "11. Find array value\n";
    cout << "12. Print\n";
    cout << "13. Quit\n";
    
}


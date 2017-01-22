#include"stdafx.h"
#include "Owl.h"
#include <stdlib.h>

#include <iostream>
using namespace std;
Owl::Owl() {}
Owl::~Owl() {}
bool Owl::Proceed(Character* Adventurer)
{
    string name;
    int intelligence=0;
    int charisma=0;
    name=Adventurer->GetName();
    cout<<"Your intelligence: "<<Adventurer->GetIntelligence()<<endl;
    cout<<"Your charisma: "<<Adventurer->GetCharisma()<<endl;
    //PART 1 of the Encounter
    cout<<"- "<<endl;
    cout<<" - "<<endl;
    cout<<"  - "<<endl;
    cout<<"o Welcome to my Old Magic Tree "<<name<<endl;
    cout<<"o It is your pleasure to be here, I hope so."<<endl;
    cout<<"o So tell me please, what are you doing here?"<<endl;
    cout<<"  - "<<endl;
    cout<<" - "<<endl;
    cout<<"- "<<endl;
    cout << "1. Well I just detoured, and I really don`t what am I doing here" << endl;
    cout << "2. Certainly it is, my Master. I came here to gain knowlede." << endl;
    cin>>menu;
    if (menu==1)
    {
        charisma--;
        cout<<endl;
        cout<< "o You`ve lost a great chance..."<<endl;
        return true;
        goto finish;
    }
    //PART 2 of the Encounter
    else if(menu==2)
    {
        cout<<"- "<<endl;
        cout<<" - "<<endl;
        cout<<"  - "<<endl;
        cout << "o I am glad to hear that my son." << endl;
        cout << "o Your way to perfection is going to be long and difficult" << endl;
        cout <<"o Now I recommend you to leave if you are not ready"<<endl;
        cout<<"  - "<<endl;
        cout<<" - "<<endl;
        cout<<"- "<<endl;
        cout << "1. Leave the Magic Tree." << endl;
        cout << "2. Stay in the Magic Tree." << endl;
        cin>>menu;
    }
    else
    {
                return true;
        goto finish;
    }
    if (menu==1)
    {
        charisma--;
        cout<<endl;
        cout<< "o You`ve lost a great chance..."<<endl;
        return false;
        goto finish;
    }
    //PART 3 of the Encounter
    else if(menu==2)
    {
        charisma ++;
        cout<<"- "<<endl;
        cout<<" - "<<endl;
        cout<<"  - "<<endl;
        cout << "o I knew it. You are so persistent." << endl;
        cout << "o Please come with me." << endl;
        cout <<"o You should now choose your path."<<endl;
        cout <<"o I am so old now. We do not have enough time. Choose only one field of training:"<<endl;
        cout<<"  - "<<endl;
        cout<<" - "<<endl;
        cout<<"- "<<endl;
        cout << "1. Magic spells." << endl;
        cout << "2. Magic mixtures." << endl;
        cout << "3. Miscellaneous"<<endl;
        cin>>menu;
    }
    else
    {   return true;
        goto finish;
    }
    //PART 4 of th Encounter
    if (menu==1)
    {
        cout<<"- "<<endl;
        cout<<" - "<<endl;
        cout<<"  - "<<endl;
        cout << "o GRREAT! My favourite one" << endl;
        cout << "o Now, some basic spells" << endl;
        cout <<"o Repeat after me:"<<endl;
        cout<<"  - "<<endl;
        cout<<" - "<<endl;
        cout<<"- "<<endl;
        string ans;
        string spell[]= {"Abrakadbra","Simsalabim","Apsik","Memento mori","Killemall","Perkele"};
        for (int i=0; i<=5; i++)
        {
            cout<<spell[i]<<endl<<endl;
            cout<<"o Repeat please."<<endl<<endl;
            cin>>ans;
            if (ans==spell[i])
            {
                intelligence++;
            }
            else intelligence--;
        }
        return true;
        goto finish;
    }
    else if (menu==2)
    {
        charisma++;
        cout<<"- "<<endl;
        cout<<" - "<<endl;
        cout<<"  - "<<endl;
        cout << "o Well I am not that good in it. But we can try it." << endl;
        cout << "o Do you already know anything about magic mixtures?" << endl;
        cout<<"  - "<<endl;
        cout<<" - "<<endl;
        cout<<"- "<<endl;
        cout <<"1. Yes"<<endl;
        cout <<"2. No"<<endl;
        cin>>menu;
        if (menu==1)
        {
            cout<<"- "<<endl;
            cout<<" - "<<endl;
            cout<<"  - "<<endl;
            cout << "o OOOHH my dear, so you are probably better in it than me." << endl;
            cout<<"  - "<<endl;
            cout<<" - "<<endl;
            cout<<"- "<<endl;
             return true;
             goto finish;
        }
        else if (menu==2)
        {
            cout<<"- "<<endl;
            cout<<" - "<<endl;
            cout<<"  - "<<endl;
            cout << "o So here is a book, read it. It is enough for your level." << endl;
            cout<<"  - "<<endl;
            cout<<" - "<<endl;
            cout<<"- "<<endl;
            intelligence++;
            return true;
            goto finish;
        }
        else
        {   return false;
            goto finish;
        }
    }
    else if (menu==3)
    {
        cout<<"- "<<endl;
        cout<<" - "<<endl;
        cout<<"  - "<<endl;
        cout << "o My dear do you like reading books?" << endl;
        cout<<"o I have an idea"<<endl;
        cout<<"o Go there, to my library. Choose a book."<<endl;
        cout<<"  - "<<endl;
        cout<<" - "<<endl;
        cout<<"- "<<endl;
        cout<<"1. Teleportation for newbies"<<endl;
        cout<<"2. How to disapear"<<endl;
        cout<<"3. Dress code for tough guys"<<endl;
        cin>>menu;
        if (menu==1)
        {
            cout << "o Good choice. You may need it ind the future." << endl;
            intelligence++;
             return true;
             goto finish;
        }
        else if (menu==2)
        {
            cout <<"o Read it, and try it as soon as possible."<<endl;
            intelligence++;
             return true;
             goto finish;
        }
        else if (menu==3)
        {
            cout<<"o HAHA, womanizer"<<endl;
            charisma++;
             return true;
             goto finish;
        }
    else
    {
        return false;
        goto finish;
    }

finish:
    intelligence=Adventurer->GetIntelligence()+intelligence;
    Adventurer->SetIntelligence(intelligence);
    charisma=Adventurer->GetCharisma()+charisma;
    Adventurer->SetCharisma(charisma);
    cout<<"Your intelligence: "<<Adventurer->GetIntelligence()<<endl;
    cout<<"Your charisma: "<<Adventurer->GetCharisma()<<endl;
    system("pause");
}
}

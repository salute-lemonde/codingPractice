#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : protected A, protected B, protected C 
{

	int val;
  
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            int rem2, rem3, rem5, count2, count3, count5; 
            count5 = count3 = count2 = rem5 = rem3 = rem2 = 0; 
            int new_val_cp = new_val; 

            /*cout << "r2: " << rem2 << " r3: " << rem3 << " r5: " << rem5 << endl; 
            cout << "c2: " << count2 << " c3: " << count3 << " c5: " << count5 << endl; */

            while(new_val_cp != 2 || 3 || 5) { 
                rem2 = new_val_cp % 2; 
                rem3 = new_val_cp % 3; 
                rem5 = new_val_cp % 5; 

                /*cout << "new_val_cp: " << new_val_cp << endl; 
                cout << rem2 << rem3 << rem5 << endl; */
                
                if(!rem2) { 
                    //cout << "got here" << endl; 
                    count2++; 
                    //cout << count2 << endl; 
                    new_val_cp = new_val_cp/2; 
                    
                }
                
                else if(!rem3) { 
                    count3++; 
                    new_val_cp = new_val_cp/3;
                }
                
                else if(!rem5) { 
                    count5++; 
                    new_val_cp = new_val_cp/5; 
                }

                else 
                    break;
            }
            
            for(int i=0; i<count2; i++) { A::func(val); }
            for(int i=0; i<count3; i++) { B::func(val); }
            for(int i=0; i<count5; i++) { C::func(val); }
                        			
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
#include<iostream>
#include<list>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct Cart
{
    int quantity;
    void* product;
    string type;
}cart;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Product{
public :
    int product_id;
    string product_name;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Fruit: public Product{
public:
    int total_quantity;
    int rate;
    float calculate_price(float quantity)
    {
        if(quantity <= total_quantity)
        {
            return rate * quantity;
        }
        return -1;
    }
    int get_discount()
    {
        return 20;
    }
    void input()
    {
        cout << "Enter Fruit Id:"<<endl;
        cin >>product_id;
        cout << "Enter fruit Name :"<<endl;
        cin >> product_name;
        cout << "Enter total Quantity: "<<endl;
        cin >> total_quantity;
        cout << "Enter the rate :"<<endl;
        cin >> rate;
    }
    void display()
    {
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout << "\tID:"<<product_id<<endl;
        cout << "\tName : "<<product_name<<endl;
        cout << "\tQuantity : "<<total_quantity<<endl;
        cout << "\tRate : "<<rate<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PackedProduct : public Product{
public:
    int total_quantity;
    int rate;
    void input()
    {
        cout << "Enter Packed_Fruit Id:"<<endl;
        cin >>product_id;
        cout << "Enter Packed_fruit Name :"<<endl;
        cin >> product_name;
        cout << "Enter total Quantity: "<<endl;
        cin >> total_quantity;
        cout << "Enter the rate :"<<endl;
        cin >> rate;
    }
    void display()
    {
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout << "\tID:"<<product_id<<endl;
        cout << "\tName : "<<product_name<<endl;
        cout << "\tQuantity : "<<total_quantity<<endl;
        cout << "\tRate : "<<rate<<endl;
        cout<<"-----------------------------------------------------------------------------------------"<<endl;
    }
    int calculate_price(int quantity)
    {
        if(quantity <= total_quantity)
        {
            return rate * quantity;
        }
        return -1;
    }
    int get_discount()
    {
        return 30;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int total_fr=0;
//int total_pp=0;                        //////GLOBAL SCOPE//////////////////
list<Fruit> fr;
list<PackedProduct> pp;
list<cart> crt;
//int crt_count;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main_menu()
{
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout << "1.Fruit"<<endl;
    cout << "2.Packet Product"<<endl;
    cout << "3.Buy from Cart"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    int ch;
    cout << "Enter choice :"<<endl;
    cin >> ch;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    return ch;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_fruit()
{
    Fruit t_fr;
    t_fr.input();
    fr.push_back(t_fr);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_pp()
{
    PackedProduct t_pp;
    t_pp.input();
    pp.push_back(t_pp);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delete_pp()
{

        list<PackedProduct>::iterator iter;
        int id=0;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout << "Enter PackedProducts id to delete"<<endl;
        cin >> id;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        for(iter = pp.begin(); iter != pp.end(); iter++){
                cout << "Data :"<< iter->product_id<<endl;
                if(id == iter->product_id){
                        pp.erase(iter);
                        break;
                }
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delete_fruit(){
        list<Fruit>::iterator iter;
        int id=0;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout << "Enter fruit id to delete"<<endl;
        cin >> id;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        for(iter = fr.begin(); iter != fr.end(); iter++){
                cout << "Data :"<< iter->product_id<<endl;
                if(id == iter->product_id){
                        fr.erase(iter);
                        break;
                }
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display_fruits()
{
    for (Fruit i :fr)
    {
        i.display();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display_pp()
{
for (PackedProduct i : pp)
    {
        i.display();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buy_fruits()
{
    display_fruits();
    cout << "Enter fruit id to buy "<< endl;
    int id = 0;
    cin >> id;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    int quantity = 0;
    list<Fruit>::iterator iter;
    for (iter = fr.begin(); iter!=fr.end() ; iter++)
    {
    if(id == iter->product_id)
        {
            iter->display();
            cout << "Enter quantity to buy :"<<endl;
            cin >> quantity;
	    iter->total_quantity-=quantity;//Decreasing the Total stock by amount of quantity purchased
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            cout <<"\tTotal Price : "<<(100-(iter->get_discount()))*(iter->calculate_price(quantity))/100<<endl;
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_to_cart_fr()
{
    display_fruits();
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"Enter the fruit id to add to cart:" <<endl;
    int id=0;
    cin >> id;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    list<Fruit>::iterator iter;
    cart t_crt;
    //PackedProduct t_pp;
    //t_pp.input();
    //pp.push_back(t_pp);
    for (iter =fr.begin(); iter!= fr.end();iter++)
    {
    if( id == iter->product_id)
        {
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            cout << "Enter quantity : "<<endl;
            cin >>t_crt.quantity;
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            t_crt.product = &(*iter);//&fr[i];
            t_crt.type="FRUIT";
            crt.push_back(t_crt);
            cout << "Added to the cart"<<endl;
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            //crt_count++;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_to_cart_pp()
{
    display_pp();
    cout<<"Enter the packed fruit id to add to cart:" <<endl;
    int id=0;
    cin >> id;
    cart t_crt;
    list<PackedProduct>::iterator iter;
    for (iter=pp.begin();iter!=pp.end();iter++)
    {
        if( id == iter->product_id)
        {
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            cout << "Enter quantity : "<<endl;
            cin >>t_crt.quantity;
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            t_crt.product = &(*iter);//&pp[i];
            t_crt.type="PP";
            crt.push_back(t_crt);
            cout << "Added to the cart"<<endl;
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            //crt_count++;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buy_pp()
{
    display_pp();
    cout << "Enter packaged packet id to buy "<< endl;
    int id = 0;
    cin >> id;
    int quantity = 0;
    list<PackedProduct>::iterator iter;
    for (iter=pp.begin() ; iter != pp.end(); iter++)
    {
        if(id == iter->product_id)
        {
            iter->display();
            cout << "Enter quantity to buy :"<<endl;
            cin >> quantity;
	    iter->total_quantity-=quantity;//Decreasing total stock by amount of quantity Packedproduct purchased
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
            cout <<"\tTotal Price : "<<(100-(iter->get_discount()))*(iter->calculate_price(quantity))/100<<endl;
	    cout<<"-----------------------------------------------------------------------------------------"<<endl;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fruits_menu()
{
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout << "1.Add fruit"<<endl;
    cout << "2.Display Fruit"<<endl;
    cout << "3.Buy fruit"<<endl;
    cout << "4. Add to cart"<<endl;
    cout << "5. Delete fruit"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    int ch = 0;
    cout << "Enter choice :"<<endl;
    cin >> ch;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    switch(ch)
    {
        case 1: add_fruit();
                break;
        case 2: display_fruits();
                break;
        case 3: buy_fruits();
                break;
        case 4: add_to_cart_fr();
                break;
        case 5: delete_fruit();
                break;
        default :
        cout << "Wrong choice"<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void packedproduct_menu()
{
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout << "1.Add Packed Product"<<endl;
    cout << "2.Display Packed Product"<<endl;
    cout << "3.Buy Packed Product"<<endl;
    cout << "4.Add to cart"<<endl;
    cout << "5.Delete Packed Products"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    int ch = 0;
    cout << "Enter choice :"<<endl;
    cin >> ch;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    switch(ch)
    {
        case 1: add_pp();
                break;
        case 2: display_pp();
                break;
        case 3: buy_pp();
                break;
        case 4: add_to_cart_pp();
                break;
        case 5: delete_pp();
                break;
        default : cout << "Wrong choice"<<endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buy_from_cart()
{
    float price_sum=0;
    list<cart>::iterator iter;
    cout<<"\t\tFINAL BILL"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"id\tName\tQuantity\tRate\tCost\tDiscount%\tDiscounted Price"<<endl;

    for(iter=crt.begin();iter!=crt.end();iter++)
    {
        if(iter->type == "FRUIT")
        {
            Fruit *pt = (Fruit*)iter->product;
     	    float discount_price_fruit=((100-(pt->get_discount()))*(pt->calculate_price(iter->quantity)))/100;
							 //Not pointer just Multiplying. CHILL!!!!!!!!!	    
            price_sum = price_sum +discount_price_fruit;
	    pt->total_quantity-=iter->quantity;//Decreasing Total stock of purchased fruit, by amount of quantity purchased
cout<<pt->product_id<<"\t"<<pt->product_name<<"\t"<<iter->quantity<<"\t\t"<<pt->rate<<"\t"<<pt->calculate_price(iter->quantity)<<"\t20\t\t"<<discount_price_fruit<<"\n";
        }//Here I used iter->quantity because there is I am adding quantity to buy in cart list not fruit list
        if(iter->type == "PP")
        {
            PackedProduct *pt = (PackedProduct*)iter->product;
	    float discount_price_packedproduct=((100-(pt->get_discount())) *(pt->calculate_price(iter->quantity)))/100;
	    						//Not pointer just Multiplying. CHILL!!!!!!!!!
            pt->total_quantity-=iter->quantity;//Decreasing total stock of packed product by amount of quantity purchased
            price_sum = price_sum + discount_price_packedproduct;
cout<<pt->product_id<<"\t"<<pt->product_name<<"\t"<<iter->quantity<<"\t\t"<<pt->rate<<"\t"<<pt->calculate_price(iter->quantity)<<"\t30\t\t"<<discount_price_packedproduct<<"\n";
        }
    }
cout<<"-----------------------------------------------------------------------------------------"<<endl;
cout << "\tCart :Total price :"<<price_sum<<endl;
//CLEARING THE CART
crt.erase(crt.begin(),crt.end());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    while(1)
    {
        switch (main_menu())
        {
            case 1 : fruits_menu();
                    break;
            case 2:  packedproduct_menu();
                    break;
            case 3:  buy_from_cart();
                    break;
            default:
            cout << "Wrong choice"<<endl;
        }
    }
    return 0;
}

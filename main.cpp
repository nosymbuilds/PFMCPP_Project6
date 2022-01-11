/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>
#include <string>

struct T
{
    T(int v, const char* n) : value(v), name(n) {}  
    int value;                                     
    std::string name;                              
};

struct Comparison                                
{
    T* compare( T& a , T& b ) 
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;

        return nullptr;
    }
};

struct U
{
    float x { 0 }, y { 0 };
    
    float modify( const float& val_ )
    {
        std::cout << "U's x value: " << x << std::endl;
        x = val_; 
        std::cout << "U's x updated value: " << x << std::endl;
        while( std::abs(y - x) > 0.001f )   
            y += 0.1f ;
        
        std::cout << "U's y updated value: " << y << std::endl;
        return y * x;
    }
};

struct Modulation
{
    static float modulate( U& that, const float& val )
    {
        std::cout << "U's x value: " << that.x << std::endl;
        that.x = val;
        std::cout << "U's x updated value: " << that.x << std::endl;
        while( std::abs(that.y - that.x) > 0.001f )   
            that.y += 0.1f ;

        std::cout << "U's y updated value: " << that.y << std::endl; 
        return that.y * that.x;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 9, "Nine" );                                             
    T t2( 7, "Seven" );                                             
    
    Comparison f;                                            
    auto* smaller = f.compare( t1 , t2 );                           
    
    if( smaller != nullptr )
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    else
        std::cout << "a nullptr was passed to compare() resulting in compare() returning nullptr" << std::endl;
       
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Modulation::modulate( u1 , updatedValue ) << std::endl;   
            
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.modify( updatedValue ) << std::endl;
}

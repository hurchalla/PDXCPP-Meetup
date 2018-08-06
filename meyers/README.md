
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0593r2.html

https://gist.github.com/shafik/848ae25ee209f698763cffee272a58f8


Strict Aliasing Rule
---------------------
From the C++17 draft standard, section [basic.lval] paragraph 11:

If a program attempts to access the stored value of an object through a glvalue of other than one of the following types the behavior is undefined:  
— the dynamic type of the object,  
— a cv-qualified version of the dynamic type of the object,  
— a type similar (as defined in 7.5) to the dynamic type of the object,  
— a type that is the signed or unsigned type corresponding to the dynamic type of the object,  
— a type that is the signed or unsigned type corresponding to a cv-qualified version of the dynamic type of the object,  
— an aggregate or union type that includes one of the aforementioned types among its elements or nonstatic data members (including, recursively, an element or non-static data member of a subaggregate or contained union),  
— a type that is a (possibly cv-qualified) base class type of the dynamic type of the object,  
— a char, unsigned char, or std::byte type.  

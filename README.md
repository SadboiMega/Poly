Implement  the  internal  representation  of  a  polynomial  (nonnegative  exponents)  as  an  array  of  
terms.  One  array  is  sufficient  to  store  one  polynomial.  One  term  is  stored  in  one  array  element;  
each term contains an exponent and a coefficient. The array element subscript is the exponent and 
the content of the element is the coefficient value. A constructor receives at most two values, the 
coefficient  of  the  term  and  the  largest  exponent  currently  expected.  (The  coefficient  may  be  
changed later using functions.) Dynamically allocate initial memory for your array using only as 
many  elements  as  needed.  (After  the  Poly  object  instantiation,  the  size  of  the  array  need  not  be  
tied  to  the  largest  exponent.  i.e.,  you  may  want  to  make  the  array  larger  when  needed,  but  
typically an array is not made smaller as it is inefficient.) 

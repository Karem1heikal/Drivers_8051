#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,no) (var+=(1<<no))
#define CLR_BIT(var,no) (var&=(~(1<<no)))
#define TOG_BIT(var,no) (var^=(1<<no))
#define GET_BIT(var,no) ((var>>no)&1)

#endif // BIT_MATH_H_

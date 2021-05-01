class Fraction
{
public:
  Fraction();
  Fraction(int n, int d = 1);

  void SetValue(int n, int d);
  void Input();
  
  void Show() const;

  int GetNumerator() const;
  int GetDenominator() const;

  double Evaluate() const;

private:
  int numerator;
  int denominator;


};

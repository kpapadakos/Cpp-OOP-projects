class House
{
public:
  House(int s);
  House(int s, char b);
  House(int s, char b, char f);

  int GetSize() const;
  int Perimeter() const;
  double Area() const; 

  void Grow();
  void Shrink();

  void SetBorder(char b);
  void SetFill(char f);

  void Draw() const;
  void Summary() const;

private:
  int Size;
  char Border;
  char Fill;
};

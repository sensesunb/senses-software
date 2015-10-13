final color WHITE = color(254, 254, 254);
final color BLACK = color(1, 1, 1);
final int TYPE_POINT = 30;

void setup() {
  size(32, 32);
  noLoop();
  smooth();
}

void draw() {
  String number;

  fill(BLACK);
  textSize(TYPE_POINT);

  for (int i = 0; i < 10; ++i)
  {
    number = "" + i;
    background(WHITE);
    text(number, 6, 28);
    save(number + ".jpg");
  }

  exit();
}

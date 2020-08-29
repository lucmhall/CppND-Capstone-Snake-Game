#include "game.h"
#include <iostream>
#include "SDL.h"
#include <vector>
#include <future>
#include <fstream>

void WriteHighScore(int score)
{
  std::string file_name = "./highscore.txt";
  try
  {

    std::ofstream file;
    file.open(file_name);

    file << std::to_string(score) << std::endl;

    file.close();
  }
  catch (int e)
  {
  }
}

int ReadHighScore()
{
  std::string file_name = "./highscore.txt";
  try
  {

    std::ifstream stream(file_name);
    std::string line;
    std::getline(stream, line);
    if (!line.empty())
    {
      return std::stoi(line);
    }
  }
  catch (int e)
  {
    return 0;
  }
  return 0;
}

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width) - 1),
      random_h(0, static_cast<int>(grid_height) - 1),
      random_food(0, 5)
{

  foods.emplace_back(std::shared_ptr<FriendlyFood>(new FriendlyFood));
  foods.emplace_back(std::shared_ptr<Food>(new Food));
  foods.emplace_back(std::shared_ptr<Food>(new Food));
  foods.emplace_back(std::shared_ptr<Food>(new Food));
  foods.emplace_back(std::shared_ptr<Food>(new Food));
  foods.emplace_back(std::shared_ptr<SpeedyFood>(new SpeedyFood));

  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  std::future<int> scoreftr = std::async(ReadHighScore);

  highScore = scoreftr.get();

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    bool gameNeedsReset = controller.HandleInput(running, snake);
    if (gameNeedsReset)
    {
      snake.Reset();
      score = 0;
      PlaceFood();

      hasWrittenHighScore = false;
    }

    Update();
    renderer.Render(snake, food, highScore);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    if (snake.alive)
    {

      // After every second, update the window title.
      if (frame_end - title_timestamp >= 1000)
      {
        renderer.UpdateWindowTitle(score, highScore, frame_count);
        frame_count = 0;
        title_timestamp = frame_end;
      }
    }
    else if (!hasWrittenHighScore)
    {
      if (score > highScore)
      {

        std::thread t = std::thread(WriteHighScore, score);
        highScore = score;
        t.join();
      }
      hasWrittenHighScore = true;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  this->food = foods[random_food(engine)];

  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);

    // Check that the location is not occupied by a snake item before placing
    if (!snake.SnakeCell(x, y))
    {
      food->setCoordinates(x, y);
      return;
    }
  }
}

void Game::Update()
{
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food->x == new_x && food->y == new_y)
  {
    score++;
    // Grow snake and increase speed.
    snake.GrowBody(food->growthRate);

    PlaceFood();

    if (snake.speed + food->speedModifier > 0.0)
    {
      snake.speed += food->speedModifier;
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
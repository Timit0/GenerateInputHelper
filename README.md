# GenerateInputHelper

**GenerateInputHelper** is a small command-line tool that generates a static class from a `project.godot` file. This utility makes it easier to reference your input actions in a type-safe way.

---

## Steps to Use GenerateInputHelper

### First Step:
- Provide the path to your `project.godot` file: ``C:/<MY>/<CUSTOM>/<PATH>/<project.godot>`` 
- **Note**: The file name does not have to be `project.godot` specifically; it can have any name as long as it points to your project file.

### Second Step:
- Specify an output path where the generated class file should be saved:  ``C:<MY>/<CUSTOM>/<PATH>``

### Third Step:
- Provide a name for the generated file & class names:  ``<your choosen name>``

----

## Example
1. C:/test/project/project.godot
2. C:/test/project/helper
3. InputHelper

### The result:
```
public static class InputHelper
{
  public static string first_action
  {
    return nameof(first_action)
  }

  public static string second_action
  {
    return nameof(second_action)
  }
}
```

## Utilities

- If I have ``Input.IsActionJustPressed("jump")`` it's dangerous. If I change the action name in my godot project I need to modify all of action using ``jump``.
- If I have ``Input.IsActionJustPressed(InputHelper.jump)`` it's a way more flexible. If I want to change the action name, I just need to change the name once.
- It's faster than typing all this class manually.

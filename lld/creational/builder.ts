/**
 * 
Problems:
    - You must remember the order of the arguments.
    - Optional parameters become confusing as their number increases.
    - Adding more options makes the constructor harder to use.
    - Validating combinations of fields becomes more difficult.
The design question: How can we construct a complex object step by step while keeping its creation readable and controlled?
That's the purpose of the Builder pattern.
 */

class User {
  constructor(
    public readonly name: string,
    public readonly email: string,
    public readonly age: number,
    public readonly role: string,
    public readonly isActive: boolean,
  ) {}
}

class UserBuilder {
  private name?: string;
  private email?: string;
  private age = 18;
  private role = "user";
  private isActive = true;

  setName(name: string): this {
    this.name = name;
    return this;
  }

  setEmail(email: string): this {
    this.email = email;
    return this;
  }

  setAge(age: number): this {
    this.age = age;
    return this;
  }

  setRole(role: string): this {
    this.role = role;
    return this;
  }

  setActive(isActive: boolean): this {
    this.isActive = isActive;
    return this;
  }

  build(): User {
    if (!this.name || !this.email) {
      throw new Error("Name and email are required to build a User.");
    }

    if (this.age < 0) {
      throw new Error("Age cannot be negative");
    }

    return new User(this.name, this.email, this.age, this.role, this.isActive);
  }
}

const user = new UserBuilder()
  .setName("Dikshant")
  .setEmail("dikshant@example.com")
  .setRole("admin")
  .setActive(true)
  .build();

console.log(user);

class ConfigManger {
  private static instance: ConfigManger;
  private constructor() {
    console.log("ConfigManger instance created");
  }

  public static getInstance(): ConfigManger {
    if (!ConfigManger.instance) {
      ConfigManger.instance = new ConfigManger();
    }
    return ConfigManger.instance;
  }
}

const cm1 = ConfigManger.getInstance();
const cm2 = ConfigManger.getInstance();

console.log(cm1 === cm2); // true

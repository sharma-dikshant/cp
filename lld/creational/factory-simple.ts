/**
 *
 *
 */

// Step 1: Define an common interface for the products
interface Notification {
  send(message: string): void;
}

// Step 2: Implement concrete products
class EmailNotification implements Notification {
  send(message: string): void {
    console.log(`Sending email notification: ${message}`);
  }
}

class SMSNotification implements Notification {
  send(message: string): void {
    console.log(`Sending SMS notification: ${message}`);
  }
}

class PushNotification implements Notification {
  send(message: string): void {
    console.log(`Sending push notification: ${message}`);
  }
}

// step 3: create the factory class

type NotificationType = "email" | "sms" | "push";

class NotificationFactory {
  static createNotification(type: NotificationType): Notification {
    switch (type) {
      case "email":
        return new EmailNotification();
      case "sms":
        return new SMSNotification();
      case "push":
        return new PushNotification();
      default:
        throw new Error("Invalid notification type");
    }
  }
}

// Step 4: Use the factory to create notifications
const emailNotification = NotificationFactory.createNotification("email");
emailNotification.send("Hello via Email!");

const smsNotification = NotificationFactory.createNotification("sms");
smsNotification.send("Hello via SMS!");

const pushNotification = NotificationFactory.createNotification("push");
pushNotification.send("Hello via Push!");

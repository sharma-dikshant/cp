interface Report {
  generate(): string;
}

class PDFReport implements Report {
  constructor() {
    console.log("pdf parser initialized.");
  }
  generate(): string {
    return "Generating PDF report";
  }
}

class HTMLReport implements Report {
  constructor() {
    console.log("html parser initialized.");
  }
  generate(): string {
    return "Generating HTML report";
  }
}

class CSVReport implements Report {
  constructor() {
    console.log("csv parser initialized.");
  }
  generate(): string {
    return "Generating CSV report";
  }
}

abstract class ReportCreator {
  abstract createReport(): Report;
  exportReport(): string {
    const report = this.createReport();
    return report.generate();
  }
}

class PDFReportCreator extends ReportCreator {
  createReport(): Report {
    return new PDFReport();
  }
}

class HTMLReportCreator extends ReportCreator {
  createReport(): Report {
    return new HTMLReport();
  }
}

class CSVReportCreator extends ReportCreator {
  createReport(): Report {
    return new CSVReport();
  }
}

const creator1: ReportCreator = new PDFReportCreator();
creator1.exportReport(); // pdf report

const creator2: ReportCreator = new CSVReportCreator();
creator2.exportReport(); // csv report

/**
 *  ANOTHER EXAMPLE OF FACTORY METHOD DESIGN PATTERN WITH NOTIFICATION SERVICE
 */

interface Notification {
  send(): void;
}

interface EmailNotification extends Notification {
  provider: EmailProvider;
}

class SMSNotification implements Notification {
  send(): void {
    console.log("Sending SMS notification");
  }
}

// Email provider concreate classes

type EmailProvider = "Gmail" | "Outlook";

class GmailNotification implements EmailNotification {
  provider: EmailProvider = "Gmail";
  send(): void {
    console.log("Sending Gmail notification");
  }
}

class OutlookNotification implements EmailNotification {
  provider: EmailProvider = "Outlook";
  send(): void {
    console.log("Sending Outlook notification");
  }
}

// creator classes for notification service
abstract class NotificationCreator {
  abstract createNotification(): Notification;
  sendNotification(): void {
    const notification = this.createNotification();
    notification.send();
  }
}

class EmailNotificationCreator extends NotificationCreator {
  private provider: EmailProvider;

  constructor(provider: EmailProvider) {
    super();
    this.provider = provider;
  }

  createNotification(): Notification {
    if (this.provider === "Gmail") {
      return new GmailNotification();
    } else if (this.provider === "Outlook") {
      return new OutlookNotification();
    } else {
      throw new Error("Unsupported email provider");
    }
  }
}

class SMSNotificationCreator extends NotificationCreator {
  createNotification(): Notification {
    return new SMSNotification();
  }
}

// Usage
const emailCreator = new EmailNotificationCreator("Gmail");
emailCreator.sendNotification(); // Sending Gmail notification

const smsCreator = new SMSNotificationCreator();
smsCreator.sendNotification(); // Sending SMS notification

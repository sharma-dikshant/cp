/**
    Suppose you're building an application that supports two cloud providers: AWS and Google Cloud.
    Your application needs two related objects:
    - A file storage service.
    - A message queue service.
    For AWS, you need S3 storage and SQS messaging. For Google Cloud, you need Cloud Storage and Pub/Sub.
    You could create each object independently using separate factories. But then a developer might accidentally combine AWS storage with Google Cloud messaging.
    The design question: How can we create a family of related objects that are guaranteed to work together, without coupling the client to their concrete classes?
That's the purpose of the Abstract Factory pattern.
 */

// step 1: Define Product Interfaces

interface Storage {
  upload(file: string): void;
}

interface MessageQueue {
  publish(message: string): void;
}

// step 2(a): implement the AWS products

class S3Storage implements Storage {
  upload(file: string): void {
    console.log(`uploading file ${file} to Amazon S3`);
  }
}
class SQSQueue implements MessageQueue {
  publish(message: string): void {
    console.log(`publishing message: ${message} to Amazon SQS`);
  }
}

// step 2(b): implement the GCP products
class GCPStorage implements Storage {
  upload(file: string): void {
    console.log(`uploading file ${file} to Google Cloud Storage`);
  }
}

class PubSubQueue implements MessageQueue {
  publish(message: string): void {
    console.log(`publishing message: ${message} to Google Pub/Sub`);
  }
}

// Step 3: Define the Abstract Factory interface
interface CloudFactory {
  createStorage(): Storage;
  createQueue(): MessageQueue;
}

// step 4: Implement concreate factories
class AWSFactory implements CloudFactory {
  createStorage(): Storage {
    return new S3Storage();
  }

  createQueue(): MessageQueue {
    return new SQSQueue();
  }
}

class GCPFactory implements CloudFactory {
  createStorage(): Storage {
    return new GCPStorage();
  }

  createQueue(): MessageQueue {
    return new PubSubQueue();
  }
}

// step 5: write client code
class FileProcessingService {
  constructor(private factory: CloudFactory) {}
  processFile(file: string) {
    const storage = this.factory.createStorage();
    const queue = this.factory.createQueue();

    storage.upload(file);
    queue.publish(file);
  }
}

const factory: CloudFactory = new AWSFactory();
const service = new FileProcessingService(factory);

service.processFile("dikshant_resume.pdf");

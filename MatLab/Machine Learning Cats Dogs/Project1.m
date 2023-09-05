% Load the training image data
cat_images = dir('cat_images/*.jpg');
dog_images = dir('dog_images/*.jpg');
other_images = dir('other_images/*.jpg');

num_cat = length(cat_images);
num_dog = length(dog_images);
num_other = length(other_images);

training_images = cell(num_cat + num_dog + num_other, 1);
training_labels = zeros(num_cat + num_dog + num_other, 1);

% Load cat images and set their labels to 1
for i = 1:num_cat
    img = imread(fullfile('cat_images', cat_images(i).name));
    img = imresize(img, [256 256]); % Resize image to 256x256
    img_gray = rgb2gray(img); % Convert image to grayscale
    training_images{i} = img_gray;
    training_labels(i) = 1;
end

% Load dog images and set their labels to 2
for i = 1:num_dog
    img = imread(fullfile('dog_images', dog_images(i).name));
    img = imresize(img, [256 256]); % Resize image to 256x256
    img_gray = rgb2gray(img); % Convert image to grayscale
    training_images{num_cat+i} = img_gray;
    training_labels(num_cat+i) = 2;
end

% Load other animal images and set their labels to 3
for i = 1:num_other
    img = imread(fullfile('other_images', other_images(i).name));
    img = imresize(img, [256 256]); % Resize image to 256x256
    img_gray = rgb2gray(img); % Convert image to grayscale
    training_images{num_cat+num_dog+i} = img_gray;
    training_labels(num_cat+num_dog+i) = 3;
end

% Combine the training images into a matrix
training_images_mat = cell2mat(reshape(training_images, [1,1,numel(training_images)]));

% Flatten the matrix into a vector for KNN classification
training_images_vec = reshape(training_images_mat, [], size(training_images_mat,3))';

% Train the KNN model
mdl = fitcknn(training_images_vec, training_labels);

% Load the test image and resize it
test_image = imread('test_image.jpg');
test_image = imresize(test_image, [256 256]);

% Convert the test image to grayscale
test_image_gray = rgb2gray(test_image);

% Classify the test image using the trained KNN model
test_image_vec = test_image_gray(:)';
predicted_label = predict(mdl, test_image_vec);

% Print the predicted label
display ('Test Image 1: ')
if predicted_label == 1
    disp('Cat');
elseif predicted_label == 2
    disp('Dog');
else
    disp ('Other');
end

% Load the test image and resize it
test_image = imread('test_image2.jpg');
test_image = imresize(test_image, [256 256]);

% Convert the test image to grayscale
test_image_gray = rgb2gray(test_image);

% Classify the test image using the trained KNN model
test_image_vec = test_image_gray(:)';
predicted_label = predict(mdl, test_image_vec);

% Print the predicted label
display ('Test Image 2: ')
if predicted_label == 1
    disp('Cat');
elseif predicted_label == 2
    disp('Dog');
else
    disp ('Other');
end

% Load the test image and resize it
test_image = imread('test_image3.jpg');
test_image = imresize(test_image, [256 256]);

% Convert the test image to grayscale
test_image_gray = rgb2gray(test_image);

% Classify the test image using the trained KNN model
test_image_vec = test_image_gray(:)';
predicted_label = predict(mdl, test_image_vec);

% Print the predicted label
display ('Test Image 3: ')
if predicted_label == 1
    disp('Cat');
elseif predicted_label == 2
    disp('Dog');
else
    disp ('Other');
end
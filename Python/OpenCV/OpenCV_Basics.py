import cv2

Cat = cv2.imread('Cat_img.jpg')

# Function to Display Image in a window
def Show_Image():
    cv2.imshow('Cute Cat', Cat)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Function to Convert and Display Image in Grayscale
def GRS():
    Gray = cv2.cvtColor(Cat, cv2.COLOR_BGR2GRAY)
    cv2.imshow('Gray Cat', Gray)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Function to Convert and Display Image in HSV Format
def HSV():
    hsv = cv2.cvtColor(Cat, cv2.COLOR_BGR2HSV)
    cv2.imshow('Dangerous Cat', hsv)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#Fucntion to Resize Image
def Resize():
    Resized = cv2.resize(Cat, [200,200])
    cv2.imshow('Resized Cat', Resized)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#Function to Crop Image
def Crop():
    Cropped = Cat[0:350, 90:450]
    cv2.imshow('Cropped Cat', Cropped)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#Function to Rotate Image by 180 Degrees
def Rotate():
    RotCat = cv2.rotate(Cat, cv2.ROTATE_180)
    cv2.imshow('Rotated Cat', RotCat)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Function to Display Pixel Values of Image
def Img_Properties():
    print("Pixel Values:\n", Cat)
    print("Image Shape:\n", Cat.shape)

#Function to Write Text on Images
def Text():
    #Parameters
    TXT = "Meoow"
    ord = (100,400)
    font = cv2.FONT_HERSHEY_SIMPLEX
    Fsize = 3
    Colour = (0, 0, 255)
    Thickness = 5

    Texted = cv2.putText(Cat, TXT, ord, font, Fsize, Colour, Thickness)
    cv2.imshow('Note: Do not Try to Meow Back', Texted)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Call the Functions Here ==>
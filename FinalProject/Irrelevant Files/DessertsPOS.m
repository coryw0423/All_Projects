function varargout = DessertsPOS(varargin)
% DESSERTSPOS MATLAB code for DessertsPOS.fig
%      DESSERTSPOS, by itself, creates a new DESSERTSPOS or raises the existing
%      singleton*.
%
%      H = DESSERTSPOS returns the handle to a new DESSERTSPOS or the handle to
%      the existing singleton*.
%
%      DESSERTSPOS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DESSERTSPOS.M with the given input arguments.
%
%      DESSERTSPOS('Property','Value',...) creates a new DESSERTSPOS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DessertsPOS_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DessertsPOS_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DessertsPOS

% Last Modified by GUIDE v2.5 23-Apr-2018 13:29:02

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DessertsPOS_OpeningFcn, ...
                   'gui_OutputFcn',  @DessertsPOS_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before DessertsPOS is made visible.
function DessertsPOS_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DessertsPOS (see VARARGIN)

% Choose default command line output for DessertsPOS
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes DessertsPOS wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = DessertsPOS_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in IceCreamConePushButton.
function IceCreamConePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to IceCreamConePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in HomePushButton.
function HomePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to HomePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
HomeScreenPOS
close(DessertsPOS)

% --- Executes on button press in TenderPushButton.
function TenderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to TenderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
TenderPOS
close(DessertsPOS)


% --- Executes on button press in AddToOrderPushButton.
function AddToOrderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to AddToOrderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ChocolateCheckBox.
function ChocolateCheckBox_Callback(hObject, eventdata, handles)
% hObject    handle to ChocolateCheckBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ChocolateCheckBox


% --- Executes on button press in VanillaCheckBox.
function VanillaCheckBox_Callback(hObject, eventdata, handles)
% hObject    handle to VanillaCheckBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of VanillaCheckBox

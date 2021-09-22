function varargout = CustomOrderPOS(varargin)
% CUSTOMORDERPOS MATLAB code for CustomOrderPOS.fig
%      CUSTOMORDERPOS, by itself, creates a new CUSTOMORDERPOS or raises the existing
%      singleton*.
%
%      H = CUSTOMORDERPOS returns the handle to a new CUSTOMORDERPOS or the handle to
%      the existing singleton*.
%
%      CUSTOMORDERPOS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CUSTOMORDERPOS.M with the given input arguments.
%
%      CUSTOMORDERPOS('Property','Value',...) creates a new CUSTOMORDERPOS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before CustomOrderPOS_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to CustomOrderPOS_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help CustomOrderPOS

% Last Modified by GUIDE v2.5 28-Apr-2018 10:10:17

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @CustomOrderPOS_OpeningFcn, ...
                   'gui_OutputFcn',  @CustomOrderPOS_OutputFcn, ...
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


% --- Executes just before CustomOrderPOS is made visible.
function CustomOrderPOS_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to CustomOrderPOS (see VARARGIN)

% Choose default command line output for CustomOrderPOS
handles.output = hObject;

FileID = fopen('Options.csv','r');
Contents = textscan( FileID, '%s%s','Delimiter',',');
fclose(FileID);

for Index = 1 : 1 : size(Contents{1},1)
    Options{Index,1} = Contents{1}{Index};
    Options{Index,2} = Contents{2}{Index};
end;

handles.Options = Options;
handles.CustomOrderButtonGroup.Children.delete();
% handles.OptionsCheckBoxes = [];

for Index = 1 : 1 : size(Options,1)
    handles.OptionsCheckBoxes( Index ) = ...
        uicontrol('Parent',handles.CustomOrderButtonGroup,...
                'units','points', ...
                'Position',[5.0, (20 * Index) + 10, 100.0, 10.0], ...        
                'style','checkbox', ...
                'string',Options{Index, 1});                        
end;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes CustomOrderPOS wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = CustomOrderPOS_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in AddToOrderPushButton.
function AddToOrderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to AddToOrderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
SelectedOptionString = '';
SelectedOptionIndex = 0;

Count = 0;
Total = 0;

for Index = 1 : 1 : size(handles.OptionsCheckBoxes,2)
    % Count = Count + handles.OptionsCheckBoxes( Index ).Value;
    if (handles.OptionsCheckBoxes( Index ).Value == true)
        Count = Count + 1;
        Total = Total + str2num(handles.Options{ Index,2});
    else
        % do nothing...
    end;
end;

disp(sprintf('Checkboxes Checked: %d', Count));
disp(sprintf('Total: $%.2f', Total ));

if Total > 0
    FileID = fopen('CurrentOrder.csv' , 'w' );
    fprintf( FileID , '%.2f' , Total );
    fclose(FileID);
    FileID = fopen('OrderHistory.csv' , 'a')
    fprintf(FileID ,'%.2f\n', Total );
    fclose(FileID);
else
end

% --- Executes on button press in HomePushButton.
function HomePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to HomePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
HomeScreenPOS
close(CustomOrderPOS)

% --- Executes on button press in TenderPushButton.
function TenderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to TenderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
TenderPOS
close(CustomOrderPOS)


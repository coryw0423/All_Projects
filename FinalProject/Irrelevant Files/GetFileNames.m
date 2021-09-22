function [ FileNames ] = GetFileNames ( DirectoryPath )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    Files = GetFiles(DirectoryPath);
    FileNames = [];
    
    if (isempty(Files)) 
        % do nothing
    else
        for x=1:length(Files)
           FileNames{x,1} = Files(x).name;
        end
    end;   
end


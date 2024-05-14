CREATE TABLE [dbo].[Book] (
    [bookid]    INT          NOT NULL,
    [bookname]  VARCHAR (40) NULL,
    [publisher] VARCHAR (40) NULL,
    [price]     INT          NULL,
    PRIMARY KEY CLUSTERED ([bookid] ASC)
);

